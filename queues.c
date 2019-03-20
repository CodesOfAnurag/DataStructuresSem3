#include<stdio.h>
#include<stdlib.h>
#define size 5

int q[size], front=-1,rear=0;

void enQu()
{
    if(front==size-1)
        printf("Full\n");
    else
    {
        printf("Enter item : ");
        scanf("%d",&q[++front]);
    }
}

void deQu()
{
    if (front==-1)
        printf("Empty\n");
    else
    {
        printf("Deleted Item : %d",q[rear++]);
        if (rear>front)
        {
            front=-1;
            rear=0;
        }
    }
}

void display()
{
    if(front==-1)
        printf("Empty\n");
    else
    {
        int i;
        printf("Queue : ");
        for(i=rear;i<=front;i++)
            printf("%d  ",q[i]);
        printf("\n");
    }
}


void main()
{
    int res;
    while(1)
    {
        printf("\n 1 - enQu \n 2 - deQu \n 3 - display \n");
        scanf("%d",&res);
        switch(res)
        {
            case 1 : enQu();    break;
            case 2 : deQu();     break;
            case 3 : display(); break;
            default : exit(0);
        }
    }
}
