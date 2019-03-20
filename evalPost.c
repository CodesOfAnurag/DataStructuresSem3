#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float s[100];
int top=-1;

void push(float item)
{
    s[++top]=item;
}

float pop()
{
    return s[top--];
}

int is_oper(char a)
{
    if (a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
        return 1;
    else
        return 0;
}

void main()
{
    char postfix[100],i=0;
    gets(postfix);
    while(postfix[i]!='\0')
    {
        float op1, op2;
        char item = postfix[i];
        if (is_oper(item)==0)
        {
            float m;
            printf("Enter Value for %c : ",item);
            scanf("%f",&m);
            push(m);
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch(item)
            {
            case '+':
                push(op1+op2);
                break;
            case '-':
                push(op1-op2);
                break;
            case '/':
                push(op1/op2);
                break;
            case '*':
                push(op1*op2);
                break;
            case '^':
                push(pow(op1,op2));
                break;
            }
        }
        i++;
    }
    printf("result : %f",s[0]);

}
