
#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *llink, *rlink;
}*head=NULL, *ptr, *temp;

void insBeg()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    head->llink=temp;
    temp->rlink=head;
    head=temp;
}

void insEnd()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&temp->data);
    ptr=head;
    if (ptr!=NULL)
    {
        while(ptr->rlink!=NULL)
            ptr=ptr->rlink;
        ptr->rlink=temp;
        temp->llink=ptr;
        temp->rlink=NULL;
    }
    else
    {
        temp->rlink=temp->llink=NULL;
        head=temp;
    }
}

int countNode()
{
    int count=0;
    ptr=head;
    while (ptr!=NULL)
    {
        ptr=ptr->rlink;
        count++;
    }
    return count;
}

void insPos()
{
    int pos, count = countNode();
    printf("Enter Position : ");
    scanf("%d",&pos);
    if (pos==1)     insBeg();
    else if (pos==count+1)      insEnd();
    else if (pos>1 & pos<count+1)
    {
        int i;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&temp->data);
        ptr=head;
        for (i=1;i<pos-1;i++)
            ptr=ptr->rlink;
        temp->llink=ptr->llink;
        temp->rlink=ptr;
        ptr->llink->rlink=temp;
        ptr->llink=temp;
    }
    else
        printf("Invalid Position\n");
}

void display()
{
    ptr=head;
    if(ptr==NULL)   printf("Empty List\n");
    else
    {
        while (ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->rlink;
        }
        printf("\n");
    }
}

void delBeg()
{
    if (head==NULL)   printf("Empty List\n");
    else
    {
        ptr=head;
        head=head->rlink;
        free(ptr);
    }
}

void delEnd()
{
    if (head==NULL)   printf("Empty List\n");
    else
    {
        ptr=head;
        while(ptr->rlink!=NULL)
        {
            temp=ptr;
            ptr=ptr->rlink;
        }
        temp->rlink=NULL;
        free(ptr);
    }
}

void delPos()
{
    int pos, count = countNode();
    printf("Enter Position : ");
    scanf("%d",&pos);
    if (pos==1)     delBeg();
    else if (pos>1 & pos<=count)
    {
        int i;
        ptr=head;
        for(i=1;i<pos;i++)
        {
            temp=ptr;
            ptr=ptr->rlink;
        }
        temp->rlink=ptr->rlink;
        ptr->rlink->llink=temp;
        free(ptr);
    }
    else
        printf("Invalid Position\n");
}

void main()
{
    int res;
    while (1)
    {
        printf(" 1 - insBeg \n 2 - insEnd \n 3 - insPos \n 4 - display \n 5 - delBeg \n 6 - delEnd \n 7 - delPos \n 8 - Exit\nEnter Response : ");
        scanf("%d",&res);
        switch(res)
        {
            case 1: insBeg(); break;
            case 2: insEnd(); break;
            case 3: insPos(); break;
            case 4: display(); break;
            case 5: delBeg(); break;
            case 6: delEnd(); break;
            case 7: delPos(); break;
            case 8: exit(0); break;
        }
    }
}
