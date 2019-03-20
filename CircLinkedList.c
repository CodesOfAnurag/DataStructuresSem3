#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *link;
} *last=NULL, *ptr, *temp;



void insBeg()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&temp->data);
    if (last==NULL)
    {
        last=temp;
        temp->link=last;
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
    }
}

void insEnd()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&temp->data);
    if(last == NULL)
    {
        last=temp;
        last->link=last;
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
        last=temp;
    }
}

int countNode()
{
    int count=0;
    if (last==NULL)     return(count);
    else
    {
        ptr=last->link;
        do
        {
            count++;
            ptr=ptr->link;
        }while (ptr!=last->link);
        return count;
    }
}

void display()
{
    if (last==NULL)     printf("Empty\n");
    else
    {
        ptr=last->link;
        do
        {
            printf("%d  ",ptr->data);
            ptr=ptr->link;
        }while(ptr!=last->link);
    }
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
        ptr=last->link;
        for (i=1;i<pos-1;i++)
            ptr=ptr->link;
        temp->link=ptr->link;
        ptr->link=temp;
    }
    else
        printf("Invalid Position\n");
}

void delBeg()
{
    if (last==NULL)     printf("Empty\n");
    else if (last==last->link)
    {
        ptr=last;
        last=NULL;
        free(ptr);
    }
    else
    {
        ptr=last->link;
        last->link=ptr->link;
        free(ptr);
    }
}

void delEnd()
{
    if (last==NULL)     printf("Empty\n");
    else if (last==last->link)
    {
        ptr=last;
        last=NULL;
        free(ptr);
    }
    else
    {
        ptr=last->link;
        while(ptr->link!=last)
            ptr=ptr->link;
        temp=last;
        ptr->link=temp->link;
        last=ptr;
        free(temp);
    }
}

void delPos()
{
    int pos, count=countNode();
    printf("Enter Position : ");
    scanf("%d",&pos);
    if (pos==1)     delBeg();
    else if (pos>1 & pos<=count)
    {
        int i;
        ptr=last->link;
        for (i=1;i<pos;i++)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        temp->link=ptr->link;
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
        printf("\n 1 - insBeg \n 2 - insEnd \n 3 - insPos \n 4 - display \n 5 - delBeg \n 6 - delEnd \n 7 - delPos \n 8 - Exit\nEnter Response : ");
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
