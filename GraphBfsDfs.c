#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
int Queue[max],Stack[max],front=-1,rear=-1;top=-1;
struct Graph
{
    int v,e;
    int *mat;
};
struct Graph Initialize(int v,int e)
{
    struct Graph g;
    int i;
    g.mat=(int *)malloc(sizeof(int)*(v*v));
    g.e=e;
    g.v=v;
    // printf(" %u ",g.mat);
    // printf(" %u ",(g.mat+4+2));
    for(i=0;i<v*v;i++)
    {
        *(g.mat+i)=0;

    }
    for(int i=0;i<g.e;i++)
    {
        printf("\nEnter vertices 1 to vertices 2 : ");
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        *(g.mat+((v1*v)+v2))=1;
    }
    return g;
}
void display(struct Graph g)
{
    int i;
    printf("\n");
    for(i=0;i<g.v;i++)
    {
        for(int j=0;j<g.v;j++)
         {
            printf(" %d",*(g.mat+(g.v*i)+j));
         }
         printf("\n");
    }
}
void inQue(int ele)
{
    if(rear==max-1)
    {
      return;  
    }
    if(rear==-1)
    {
        front=rear=0;
        Queue[rear]=ele;
    }
    else{
     rear++;
     Queue[rear]=ele;
    }
}
int reQue()
{
    int rele;
    if(front==-1)
    {
        return -1;
    }
    if(front==rear)
    {
     rele=Queue[front];
     front=rear=-1;
    }
    else{
    rele=Queue[front];
    front++;
    }
    return rele;
}
void push(int ele)
{
    if(top==max-1)
    {
        return;
    }
    else 
    {
        top++;
        Stack[top]=ele;
    }
}
int pop()
{
    int rele;
    if(top==-1)
    {
        return -1;
    }
    else{
        rele=Stack[top];
        top--;
    }
    return rele;
}
void Bfs(struct Graph g,int start)
{
    int visited[g.v];
    for(int i=0;i<g.v;i++)
    {
        visited[i]=0;
    }
    inQue(start);
    visited[start]=1;
    printf("\nBFS : ");
    while (front!=-1)
    {
        int node=reQue();
        printf(" %d",node);

        for(int i=0;i<g.v;i++)
        {
            if(*(g.mat+(node*g.v)+i)==1 && !visited[i])
            {
                inQue(i);
                visited[i]=1;
            }
        }
    }
    

}
void Dfs(struct Graph g,int start)
{
    int visited[g.v];
    for(int i=0;i<g.v;i++)
    {
        visited[i]=0;
    }
   push(start);
   printf("\nDFS : ");
   while (top!=-1)
   {
    int node=pop();
    if(!visited[node])
    {
    printf(" %d",node);
    visited[node]=1;
    }
    for(int i=0;i<g.v;i++)
        {
            if(*(g.mat+(node*g.v)+i)==1 && !visited[i])
            {
                push(i);
            }
        }
   }
   
}

void main()
{
    struct Graph g;
    int vertices,edges;
    printf("\nEnter vertices : ");
    scanf("%d",&vertices);
    printf("\nEnter edges : ");
    scanf("%d",&edges);
    g=Initialize(vertices,edges);
    Bfs(g,0);
    Dfs(g,0);
    display(g);

}