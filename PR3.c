// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#define max 5
void push(int Stack[],int *top1,int *top2)
{
    int stack_choice=0,ele;
    printf("\n1 For Push in Stack 1 ");
    printf("\n2 For Push in Stack 2 ");
    printf("\nEnter your choice : ");
    scanf("%d",&stack_choice);
    
    if(stack_choice==1)
    {
        if(*top1==(*top2)-1)
        {
            printf("\nStack is overflow.");
        }
        else
        {
           printf("\nEnter element : ");
           scanf("%d",&ele);
           (*top1)++;
           Stack[*top1]=ele;
           printf("\n%d inserted at index : %d in Stack 1 ",ele,*top1);
        }
    }
    else if(stack_choice==2)
    {
        if(*top2==(*top1)+1)
        {
            printf("\nStack is overflow.");
        }
        else
        {
           printf("\nEnter element : ");
           scanf("%d",&ele);
           (*top2)--;
           Stack[*top2]=ele;
           printf("\n%d inserted at index : %d in Stack 2 ",ele,*top2);
        }
    }
}

int main() {
   int Stack[max],t1=-1,t2=max,*top1=&t1,*top2=&t2,choice;
   while(1)
   {
       printf("\n1 For push ");
       scanf("%d",&choice);
       
       switch(choice)
       {
            case 1:
                push(Stack,top1,top2);
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("\nEnter valid choice");
                break;
       }
   }

    return 0;
}
