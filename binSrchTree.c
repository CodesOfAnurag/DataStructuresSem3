#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *rchild, *lchild;
} *root=NULL, *temp, *ptr, *parent=NULL ;

void create()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&temp->data);
    temp->rchild=NULL;
    temp->lchild=NULL;
    if (root==NULL)
        root=temp;

    else
    {
        ptr=root;
        while(ptr)
        {
            parent = ptr;
            if (ptr->data > temp->data)
                ptr=ptr->lchild;
            else if (ptr->data < temp->data)
                ptr=ptr->rchild;
            else
            {
                return;
                printf("Node Exists \n");
            }
        }

        if (parent->data > temp->data)
            parent->lchild=temp;
        else
            parent->rchild=temp;
    }
}

void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->lchild);
        printf("%d  ",tree->data);
        inorder(tree->rchild);
    }
}
void main()
{
    int res;
    while(1)
    {
        printf(" enter item - 1\n display - 2\nEnter Res : ");
        scanf("%d",&res);
        if(res==2)
        {
            printf(" INORDER : ");
            inorder(root);
            printf("\n");
        }
        else
        {
            create();
        }
    }
}
