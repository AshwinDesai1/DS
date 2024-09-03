#include<stdio.h>
#include<conio.h>
int prec(char c)
{
    int p;
    if(c=='+' || c=='-')
    {
        p=1;
    }
    else if(c=='*' || c=='/')
    {
        p=2;
    }
    else
    {
        p=0;
    }
    return p;
}
void infixToPostfix(char inf[])
{
    int i=0,top=-1;
    char Stack[10];
    char c;
    while (inf[i]!=';')
    {
        c=inf[i];

        if(c=='+' || c=='-' || c=='*' || c== '/')
        {
            if(Stack[top]==-1)
            {
                top++;
                Stack[top]=c;
            }
            x:
            if(prec(Stack[top])<=prec(c))
            {
                if(top>=0)
                {
                  printf("%c",Stack[top]);
                  top--;
                  goto x;
                }
            }
            else
            {
                top++;
                Stack[top]=c;
            }
        }
        else
        {
            printf("%c",inf[i]);
        }
        i++;
    }
    if(c==";")
    {
      while(Stack[top]>=0)
      {
        printf("%c",Stack[top]);
        top--;
      }
    }
    
}
void main()
{
    char infix[20];
    printf("\nEnter infix : ");
    scanf("%c",infix);
    infixToPostfix(infix);
}
