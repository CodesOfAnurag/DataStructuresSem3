#include<stdlib.h>
#include<stdio.h>

void toh(int n, char src, char temp, char dest)
{
    if (n==1)
        printf("Move from %c to %c\n",src,dest);
    else
    {
        toh(n-1,src,dest,temp);
        printf("Move from %c to %c\n",src,dest);
        toh(n-1,temp,src,dest);
    }
}

void main()
{
    toh(3,'a','b','c');
}
