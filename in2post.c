#include<stdio.h>
#include<stdlib.h>
char s[100],top=-1;

void push(char item)
{
    s[++top]=item;
}

char pop()
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
int prec(char a)
{
    if (a=='+'||a=='-')
        return 1;
    else if (a=='*'||a=='/')
        return 2;
    else if (a=='^')
        return 3;
    else
        return 0;
}

void main()
{
    char infix[100], postfix[100],i=0,j=0;
    gets(infix);
    while (infix[i]!='\0')
    {
        char item = infix[i];
        if(is_oper(item))
        {
            while (prec(s[top])>=prec(item))
            {
                postfix[j++]=pop();
            }
            push(item);
        }
        else if(item=='(')
            push(item);
        else if(item==')')
        {
            char temp;
            while(s[top]!='(')
                postfix[j++]=pop();
            temp=pop();
        }
        else
            postfix[j++]=item;
        i++;
    }
    while(top!=-1)
        postfix[j++]=pop();
    postfix[j++]='\0';
    puts(postfix);
}
