#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node *insert(struct node *head,int ele)
{
    struct node *Neww,*curr,*previos;
    Neww=(struct node*)malloc(sizeof(struct node));
    Neww->data=ele;
    Neww->next=Neww;
    Neww->prev=Neww;
    if(head==NULL)
    {
        head=Neww;
    }
    curr=head;
    previos=NULL;
    while (curr->next!=head && curr->data<ele)
    {
        previos=curr;
        curr=curr->next;
    }
    if(previos==NULL&& ele<=curr->data)
    {
        Neww->next=curr;
        Neww->prev=curr->prev;
        curr->prev->next=Neww;
        curr->prev=Neww;
        head=Neww;
    }else{
        if(ele>curr->data)
        {
            Neww->next=curr->next;
            curr->next->prev=Neww;
            curr->next=Neww;
            Neww->prev=curr;
        }
        else{
            Neww->next=curr;
            Neww->prev=previos;
            previos->next=Neww;
            curr->prev=Neww;
        }

    }
    return head;
    
}
void display(struct node *head)
{
    struct node *curr;
    curr=head;
    if(head==NULL)
    {
        return;
    }
    while (curr->next!=head)
    {
        printf(" %d",curr->data);
        curr=curr->next;
    }
    printf(" %d",curr->data);

}
struct node *Delete(struct node *head,int ele)
{
    struct node *curr,*previos;
    if(head==NULL)
    {
        return head;
    }
    curr=head;
    previos=NULL;
    while (curr->data!=ele&&curr->data<=ele)
    {
        printf("\nWhile");
        previos=curr;
        curr=curr->next;
    }

    if(head->data==ele&&head->next==head)
    {
        printf("\nIf");
        free(curr);
        head=NULL;
        return head;
    }
    else if(head->data==ele&&head->next!=head)
    {
        printf("\n1else If");
        head->next->prev=head->prev;
        head->prev->next=head->next;
        head=head->next;
        free(curr);
    }
    else if(curr->data==ele)
    {
        printf("\nelse If");
        curr->next->prev=curr->prev;
        curr->prev->next=curr->next;
        free(curr);
    }
    else{
          printf("\nElement not found");
    }
    return head;
}
void main()
{
struct node *head=NULL;
int c,ele;
while (1)
{
        printf("\n1:insert");
        printf("\n2:Display");
        printf("\n3:Delete");
        printf("\n4:exit");
        printf("\nEnter your choice:");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("\nEnter element : ");
                scanf("%d",&ele);
                head=insert(head,ele);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("\nEnter element for remove : ");
                scanf("%d",&ele);
                head=Delete(head,ele);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid input");
                break;
        }
}

}