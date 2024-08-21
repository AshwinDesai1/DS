#include<stdio.h>
#include<conio.h>
struct node
{
 int ele;
 struct node *next;
};

struct node *insertLL(struct node *head,int ele)
{
  struct node *neww;
  neww=(struct node*)malloc(sizeof(struct node));
  if(head==0)
  {
    head=neww;
    neww->ele=ele;
    neww->next=NULL;
  }
  else
  {
    neww->next=head;
    head=neww;
  }
  return head;
}
void display(struct node *head)
{
 struct node *curr;
 curr=head;
 if(head==0)
 {
  printf("Empty");
 }
 else
 {
   printf("Display");
  while(curr->next!=NULL)
  {
   printf("Display loop");
   printf("%d",curr->ele);
  }
  }
}
void main()
{
 struct node *head=NULL;
 int ele,ch;
 clrscr();
  while(1)
  {
   printf("\n1 for insert");
   printf("\n2 for insert");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
      printf("\nEnter element : ");
      scanf("%d",&ele);
      head=insertLL(head,10);
      break;
    case 2:
      display(head);
      break;
    case 3:
       exit(0);
   }
 }
 getch();
}