#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *right, *left;
} node;

node *stack[40];
int top=-1;

void push(node *ptr)
{
    stack[++top]=ptr;
}

node *pop()
{
    return stack[top--];
}

int is_opr(char opr)
{
    if ( opr == '-' || opr == '+' || opr == '*' || opr == '/' )
        return 1;
    else
        return 0;
}

void oprtor(char ch)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->right=pop();
    temp->left=pop();
    temp->data=ch;
    push(temp);
}

void oprand(char ch)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->right=NULL;
    temp->left=NULL;
    temp->data=ch;
    push(temp);
}

int calc(node *ptr)
{
    char ch = ptr->data;
    if (is_opr(ch))
    {
        switch(ch)
        {
        case '+' :
            return calc(ptr->left)+calc(ptr->right);
            break;

        case '-' :
            return calc(ptr->left)-calc(ptr->right);
            break;

        case '*' :
            return calc(ptr->left)*calc(ptr->right);
            break;

        case '/' :
            return calc(ptr->left)/calc(ptr->right);
            break;

        }
    }
    else
        return ptr->data-48;
}

void inord(node *tree)
{
    if (tree!=NULL)
    {
        inord(tree->left);
        printf("%c ", tree->data);
        inord(tree->right);
    }
}

void main()
{
    char post[40];
    int res,i;
    gets(post);
    for (i=0; post[i]!='\0'; i++)
    {
        char item = post[i];
        if (is_opr(item))
            oprtor(item);
        else
            oprand(item);
    }
    res = calc(stack[top]);
    printf("Inorder : ");
    inord(stack[top]);
    printf("\nResult : %d",res);

}
