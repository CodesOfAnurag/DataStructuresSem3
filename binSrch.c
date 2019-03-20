#include<stdlib.h>
#include<stdio.h>
int ar[5],item;
void binSrch(int a, int b)
{
    int mid = (a+b)*0.5;
    if (a<=b)
    {
        if (ar[mid]==item)
            printf("Found\n");
        else if (ar[mid]>item)   binSrch(a,mid-1);
        else binSrch(mid+1,b);
    }
    else
        printf("NotFound\n");
}

void main()
{
    int i=0;
    printf("Enter Item : ");
    for(i=0;i<5;i++)
        scanf("%d",&ar[i]);
    printf("Enter Search Item : ");
    scanf("%d",&item);
    binSrch(0,4);
}
