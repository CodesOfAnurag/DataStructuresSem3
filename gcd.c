#include<stdlib.h>
#include<stdio.h>

int gcd(int a, int b)
{
    if (a%b==0)
        return b;
    else
        gcd(b,a%b);
}

void main()
{
    printf("%d\n",gcd(10,15));
    printf("%d\n",gcd(10,14));
    printf("%d\n",gcd(10,30));
    printf("%d\n",gcd(10,11));
    printf("%d\n",gcd(10,121));
    printf("%d\n",gcd(10,13));
    printf("%d\n",gcd(3,15));
    printf("%d\n",gcd(6,15));
}
