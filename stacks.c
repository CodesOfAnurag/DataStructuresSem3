#include<stdio.h>
#include<stdlib.h>
#define size 5

int s[size], top=-1;

void push()
{
    if(top==size-1)
        printf("Full\n");
    else
        {
            printf("Enter Item : ");
            scanf("%d",&s[++top]);
        }
}

void pop()
{
    if (top==-1)
        printf("Empty\n");
    else
    {
        printf("Deleted item : %d", s[top--]);
    }
}

void display()
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
    int res;
    while(1)
    {
        printf("\n 1 - push \n 2 - pop \n 3 - display \n");
        scanf("%d",&res);
        switch(res)
        {
            case 1 : push();    break;
            case 2 : pop();     break;
            case 3 : display(); break;
            default : exit(0);
        }
    }

}
