#include<stdio.h>
#include<stdlib.h>
#define size 5

void push(int *top, int *s)
{
    if(*top==size-1)
        printf("Full\n");
    else
        {
            printf("Enter Item : ");
            scanf("%d",&s[++*top]);
        }
}

void pop(int *top, int *s)
{
    if (*top==-1)
        printf("Empty\n");
    else
    {
        printf("Deleted item : %d", s[(*top)--]);
    }
}

void display(int top, int s[])
{
    if (top==-1)
        printf("Empty\n");
    else
    {
        int i;
        printf("stack : ");
        for (i=0;i<=top;i++)
            printf("%d\t",s[i]);
        printf("\n");
    }
}

void main()
{
    int s[size], top=-1;
    int res;
    while(1)
    {
        printf("\n 1 - push \n 2 - pop \n 3 - display \n");
        scanf("%d",&res);
        switch(res)
        {
            case 1 : push(&top,s);    break;
            case 2 : pop(&top,s);     break;
            case 3 : display(top,s); break;
            default : exit(0);
        }
    }
}
