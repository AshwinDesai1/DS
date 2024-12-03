#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *l,*r; 
};
struct Node *Insert(struct Node *root,int ele)
{
    struct Node *nev, *curr, *prev;
    nev=(struct Node *)malloc(sizeof(struct Node));
    nev->data=ele;
    nev->l=NULL;
    nev->r=NULL;
    prev=NULL;
    curr=root;
    if(root==NULL)
    {
      root=nev;
      return root;
    }
    while (curr!=NULL)
    {
        prev=curr;
        if(curr->data>ele)
        {
            curr=curr->l;
        }
        else
        {
            curr=curr->r;
        }
    }
    if(prev->data>ele)
        prev->l=nev;
    else
        prev->r=nev;
    return root;
}
void inorder(struct Node *root)
{
    if(root==NULL)
        return;
    inorder(root->l);
    printf("%d ",root->data);
    inorder(root->r);
}
void preorder(struct Node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->l);
    preorder(root->r);
}
void postorder(struct Node *root)
{
    if(root==NULL)
        return;
    postorder(root->l);
    postorder(root->r);
    printf("%d ",root->data);
}
void main()
{
   struct Node *root=NULL;
   int ele,choice;
   while (1)
   {
     printf("\n1 for insert ");
     printf("\n2 for inorder traverse ");
     printf("\n3 for preorder traverse ");
     printf("\n4 for postorder traverse ");
     printf("\n5 for exit.");
     printf("\nEnter your choice : ");
     scanf("%d",&choice);

     switch (choice)
     {
     case 1:
        printf("Enter Element : ");
        scanf("%d",&ele);
        root=Insert(root,ele);
        printf("Root : %d",root->data);
        break;
    case 2:
        printf("\nElement in Inorder : ");
        inorder(root);
        break;
    case 3:
        printf("\nElement in preorder : ");
        preorder(root);
        break;
    case 4:
        printf("\nElement in postorder : ");
        postorder(root);
        break;
    case 5 :
        exit(0);    
     default:
        printf("Enter valid choice.");
        break;
     }
   }
}

