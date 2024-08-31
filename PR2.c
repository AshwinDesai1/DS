#include<stdio.h>
#include<stdlib.h>
#define max 5

int push(int arr[],int top)
{
 if(top==max-1)
 {
  printf("Stack Overflow...");
 }
 else
 {
  int ele;
  printf("\nEnter element : ");
  scanf("%d",&ele);
  if(top==-1)
  {
    top=0;
    arr[top]=ele;
  }
  else
  {
    top+=1;
    arr[top]=ele;
  }
  printf("\n%d inserted succesfully..",ele);
 }
 return top;
}
int pop(int arr[],int top)
{
  if(top==-1)
  {
    printf("\nEmpty Stack...");
  }
  else
  {
   printf("\nRemoved element : %d ",arr[top]);
   top--;
  }
  return top;
} 
void display(int arr[],int top)
{
  if(top==-1)
  {
    printf("\nEmpty Stack..\n");
  }
  else
  {
    int i=0;
    for(i;i<=top;i++)
    {
      printf("%d ",arr[i]);
    }
  
  }
}
void modify(int arr[],int top)
{
    if(top!=-1)
    {
    int ele,nele,i,c=0;
    printf("\nEnter old element that you want modify : ");
    scanf("%d",&ele);
    printf("\nEnter new element : ");
    scanf("%d",&nele);
    for(i=0;i<=top;i++)
    {
        if(arr[i]==ele)
        {
            arr[i]=nele;
            c++;
        }
        
    }
    if(c==0)
    {
        printf("\nElement not found.");
    }
    else
    {
        if(c==1)
          printf("\n%d Element updated...",c);
        else
          printf("\n%d Elements updated...",c);
    }
    }
    else
    {
         printf("\nEmpty stack.\n");
    }
    
}
void peep(int arr[],int top)
{
    if(top==-1)
    {
        printf("\nEmpty Stack...");
    }
    else
    {
        int ele,i,c;
        printf("\nEnter element that you want to find : ");
        scanf("%d",&ele);
        for(i=0;i<=top;i++)
        {
            if(arr[i]==ele)
            {
                printf("\nElemet found at index : %d",i);
                c++;
            }
        }
        if(c==1)
            printf("\n%d Element found...",c);
        else
            printf("\n%d Elements found...",c);
    }
}
int main()
{
 int arr[max],top=-1,choice;
 while(1)
 {
  printf("\n1 for Push\n");
  printf("2 for Pop\n");
  printf("3 for Display\n");
  printf("4 for Modify\n");
  printf("5 for peep\n");
  printf("6 for Exit\n");
  printf("Enter choice : ");
  scanf("%d",&choice);

  switch (choice)
  {
  case 1:
    top=push(arr,top);
    break;
  case 2:
    top=pop(arr,top);
    break;
  case 3:
    display(arr,top);
    break;
  case 4:
    modify(arr,top);
    break;
  case 5:
    peep(arr,top);
    break;
  case 6:
    exit(0);

  default:
  printf("\nEnter valid choice");
    break;
  }

 }
return 0;
}
