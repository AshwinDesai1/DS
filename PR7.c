#include <stdio.h>
#include<stdlib.h>
#define max 5
void insert(int DQ[],int *flt, int *rlt,int *frt,int *rrt)
{
    int queue_choice=0,ele;
    x:
    printf("\n1 For insert in Queue from Left end.");
    printf("\n2 For insert in Queue from Right end.");
    printf("\nEnter your choice : ");
    scanf("%d",&queue_choice);
    if(*rlt==*rrt-1)
    {
        printf("\nQueue is full.");
    }
    else 
    {
        printf("\nEnter element : ");
        scanf("%d",&ele);
        if(*f==-1 && *r==-1)
        {   
            
             *f=*r=0;
             Q[*f]=ele;
        
        }
        else
        {
            
            (*r)++;
            Q[*r]=ele;
        
        }
        printf("%d inserted at index %d",ele,*r);
    }
}
void Delete(int DQ[],int *f, int *r)
{
    int rele,ind;
    if(*f==-1)
    {
        printf("\nQueue is empty.");
    }
    else 
    {
        if(*f==*r)
        {   
             rele=Q[*f];
             ind=*f;
             *f=*r=-1;
        
        }
        else
        {
            rele=Q[*f];
            ind=*f;
            (*f)++;
        
        }
        printf("%d removed from index %d",rele,ind);
    }
}
void modify(int DQ[],int *f, int *r)
{
    int nele,oele,fc=0,i;
    if(*f==-1)
    {
        printf("\nQueue is empty.");
    }
    else 
    {
        printf("\nEnter old element that you want to modify : ");
        scanf("%d",&oele);
        for(i=*f;i<=*r;i++)
        {
            if(Q[i]==oele)
            {
              printf("\nEnter new element : ");
              scanf("%d",&nele);
              Q[i]=nele;
              printf("\n%d updated for %d.",oele,nele);
              fc++;
            }
        }
        if(fc==0)
        {
            printf("Element not found");
        }
    }
}
void display(int DQ[],int *f, int *r)
{
    int i;
    if(*f==-1)
    {
        printf("\nQueue is empty.");
    }
    else 
    {
        printf("\n");
        for(i=*f;i<=*r;i++)
        {
            printf("%d ",Q[i]);
        }
    }
}
int main() {
    int DQ[max],f=-1,r=-1,*fp=&f,*rp=&r,choice;
   while(1)
   {
       printf("\n\n1 For insert ");
       printf("\n2 For delete ");
       printf("\n3 For modify ");
       printf("\n4 For display");
       printf("\n5 For exit");
       printf("\nEnter your choice : ");
       scanf("%d",&choice);
       
       switch(choice)
       {
            case 1:
                insert(DQ,fp,rp);
                break;
            case 2:
                Delete(DQ,fp,rp);
                break;
            case 3:
                modify(DQ,fp,rp);
                break;
            case 4:
                display(DQ,fp,rp);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nEnter valid choice");
                break;
       }
   }


    return 0;
}