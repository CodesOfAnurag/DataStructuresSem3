#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *rchild, *lchild;
} *root=NULL, *temp, *ptr;

int is_lchild(struct node *tree)
{
    int ch;
    printf("Do you want to create Left Child For %d (1 or 0) : ",tree->data);
    scanf("%d",&ch);
    return ch;
}

int is_rchild(struct node *tree)
{
    int ch;
    printf("Do you want to create Right Child For %d (1 or 0) : ",tree->data);
    scanf("%d",&ch);
    return ch;
}

void create(struct node *tree)
{
    tree=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&tree->data);
    temp=(struct node*)malloc(sizeof(struct node));
    if (is_lchild(tree))
    {
        temp=NULL;
        create(temp);
        tree->lchild=temp;
    }

    else
       tree->lchild=NULL;

    if (is_rchild(tree))
    {
        temp=NULL;
        create(temp);
        tree->rchild=temp;
    }

    else
        tree->rchild=NULL;
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

void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d  ",tree->data);
        preorder(tree->lchild);
        preorder(tree->rchild);
    }
}

void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->lchild);
        postorder(tree->rchild);
        printf("%d  ",tree->data);
    }
}

void main()
{
    root=(struct node*)malloc(sizeof(struct node));

    create(root);

    printf(" INORDER : ");
    inorder(root);
    printf("\n");
    printf(" PREORDER : ");
    preorder(root);
    printf("\n");
    printf(" POSTORDER : ");
    postorder(root);
    printf("\n");
}
