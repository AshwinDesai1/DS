#include<stdio.h>
#include<stdlib.h>
#define max 5

int add(int arr[],int top)
{
 if(top==max-1)
 {
  printf("Array Overflow...");
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
int delete(int arr[],int top)
{
  if(top==-1)
  {
    printf("\nEmpty array...");
  }
  else
  {
   int rind;
   printf("Enter index : ");
   scanf("%d",&rind);
   if(rind>top)
   {
       printf("Please enter correct index");
   }
   else
   {
       printf("\nRemoved element : %d ",arr[rind]);
       arr[rind]=0;
       int i=0,n=0;
       while(n<=top)
       {
           if(arr[n]!=0)
           {
               arr[i]=arr[n];
               i++;
           }
           n++;
       }
       top--;
   }
  }
  return top;
} 
void display(int arr[],int top)
{
  if(top==-1)
  {
    printf("\nEmpty array..\n");
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
         printf("\nEmpty array.\n");
    }
    
}
void sort(int arr[],int top)
{
    int temp,i,j;
    if(top!=-1)
    {
    for(i=0;i<=top;i++)
    {
        for(j=i+1;j<=top;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    }
    else
    {
        printf("\nEmpty array.\n");
    }
}
void search(int arr[],int top)
{
    if(top==-1)
    {
        printf("\nEmpty array...");
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
 int arr[max],top=-1,ele,choice;
 printf("\nDone");
 while(1)
 {
  printf("\n1 for Add\n");
  printf("2 for Remove\n");
  printf("3 for Display\n");
  printf("4 for Modify\n");
  printf("5 for sort\n");
  printf("6 for Search.\n");
  printf("7 for Exit.\n");
  printf("Enter choice : ");
  scanf("%d",&choice);

  switch (choice)
  {
  case 1:
    top=add(arr,top);
    break;
  case 2:
    top=delete(arr,top);
    break;
  case 3:
    display(arr,top);
    break;
  case 4:
    modify(arr,top);
    break;
  case 5:
    sort(arr,top);
    break;
  case 6:
    search(arr,top);
    break;
  case 7:
    exit(0);

  default:
  printf("\nEnter valid choice");
    break;
  }

 }
return 0;
}
