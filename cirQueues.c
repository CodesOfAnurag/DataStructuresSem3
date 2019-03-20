#include<stdio.h>
#include<stdlib.h>
#define size 3

int q[size], front=-1,rear=0,count;

void enQu()
{
    if(count==size)
        printf("Full\n");
    else
    {
        printf("Enter item : ");
        front=(front+1)%size;
        count++;
        scanf("%d",&q[front]);
    }
}

void deQu()
{
    if (front==-1)
        printf("Empty\n");
    else
    {
        printf("Deleted Item : %d",q[rear]);
        rear=(rear+1)%size;
        count--;
        if (count==0)
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
        for(i=0;i<count;i++)
            printf("%d  ",q[(i+rear)%size]);
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
            default : printf("Loda");
        }
    }
}

