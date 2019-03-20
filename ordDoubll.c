#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *rlink, *llink;
} *head=NULL, *ptr, *temp;

void ins()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&temp->data);
    if (head == NULL)
    {
        temp->rlink=temp->llink=NULL;
        head=temp;
    }
    else if (temp->data > head->data)
    {
        ptr=head;
        while(ptr->rlink!=NULL && ptr->data < temp->data)
            ptr=ptr->rlink;
        if (ptr->data >temp->data)
        {
            temp->rlink=ptr;
            temp->llink=ptr->llink;
            ptr->llink->rlink=temp;
            ptr->llink=temp;
        }
        else
        {
            temp->rlink=NULL;
            temp->llink=ptr;
            ptr->rlink=temp;
        }
    }
    else
    {
        temp->rlink=head;
        head->llink=temp;
        temp->llink=NULL;
        head=temp;
    }
}

void display()
{
    ptr=head;
    if (ptr!=NULL)
    {
        while (ptr!=NULL)
        {
            printf("%d  ", ptr->data);
            ptr=ptr->rlink;
        }
        printf("\n");
    }
    else
        printf("Empty\n");
}

void main()
{
    int res;
    while(1)
    {
        printf(" 1 - insert \n 2 - display \n 3 - exit \nEnter Response : ");
        scanf("%d",&res);
        switch(res)
        {
            case 1 : ins();         break;
            case 2 : display();     break;
            case 3 : exit(0);
        }
    }
}
