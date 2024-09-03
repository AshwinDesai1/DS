#include <stdio.h>
#include <stdlib.h>
#define max 5
void insert(int DQ[], int *flt, int *rlt, int *frt, int *rrt)
{
    int queue_choice = 0, ele;
x:
    printf("\n1 For insert in Queue from Left end.");
    printf("\n2 For insert in Queue from Right end.");
    printf("\nEnter your choice : ");
    scanf("%d", &queue_choice);
    if ((*rlt) == (*rrt) - 1 || (*rrt) == (*rlt) + 1)
    {
        printf("\nQueue is full.");
    }
    else
    {
        if (queue_choice == 1)
        {
            printf("\nEnter element : ");
            scanf("%d", &ele);
            if (*flt = -1 && *rlt == -1)
            {
                *flt = *rlt = 0;
                DQ[*rlt] = ele;
            }
            else
            {
                (*rlt)++;
                DQ[*rlt] = ele;
            }
            printf("\n%d inserted at index %d from left end.", ele, *rlt);
        }
        else if (queue_choice == 2)
        {
            printf("\nEnter element : ");
            scanf("%d", &ele);
            if (*frt == max && *rrt == max)
            {
                (*frt) = max - 1;
                (*rrt) = max - 1;
                DQ[*rrt] = ele;
                printf("\nfronnt right %d", *frt);
                printf("\nrear right %d", *rrt);
            }
            else
            {
                (*rrt)--;
                DQ[*rrt] = ele;
                printf("\nfronnt right %d", *frt);
                printf("\nrear right %d", *rrt);
            }
            printf("\n%d inserted at index %d from right end.", ele, *rrt);
        }
        else
        {
            printf("\nPlease enter correct Queue number!.");
            goto x;
        }
    }
}
void Delete(int DQ[], int *flt, int *rlt, int *frt, int *rrt)
{
    int queue_choice = 0, ele, ind;
x:
    printf("\n1 For Delete in Queue from Left end.");
    printf("\n2 For Delete in Queue from Right end.");
    printf("\nEnter your choice : ");
    scanf("%d", &queue_choice);
    if (queue_choice == 1)
    {
        if ((*rlt) == -1)
        {
            printf("\nQueue is empty from left end.");
        }
        else
        {
            if ((*flt) == (*rlt))
            {
                ele = DQ[*flt];
                ind = (*flt);
                (*flt) = (*rlt) = -1;
            }
            else
            {
                ele = DQ[*flt];
                ind = (*flt);
                (*flt)++;
            }
            printf("\n%d removed at index %d from left end.", ele, ind);
        }
    }
    else if (queue_choice == 2)
    {
        if ((*rrt) == max)
        {
            printf("\nQueue is empty from right end.");
        }
        else
        {
            if ((*frt) == (*rrt))
            {
                printf("\nLeft if");
                printf("\n%d", *frt);
                ele = DQ[*frt];
                ind = (*frt);
                (*frt) = (*rrt) = max;
            }
            else
            {
                printf("\nLeft else");
                printf("\n%d", *frt);
                ele = DQ[*frt];
                ind = (*frt);
                (*frt)--;
            }
            printf("\n%d removed at index %d from right end.", ele, ind);
        }
    }
    else
    {
        printf("\nPlease enter correct Queue number!.");
        goto x;
    }
}

void modify(int DQ[], int *flt, int *rlt, int *frt, int *rrt)
{
    int queue_choice = 0, oele, nele, i, c = 0;
x:
    printf("\n1 For modify in Queue from Left end.");
    printf("\n2 For modify in Queue from Right end.");
    printf("\nEnter your choice : ");
    scanf("%d", &queue_choice);
    if (queue_choice == 1)
    {
        if ((*rlt) == -1)
        {
            printf("\nQueue is empty from left end.");
        }
        else
        {
            printf("\nEnter old element that you want to change : ");
            scanf("%d",&oele);
            for (i = (*flt); i <= (*rlt); i++)
            {
                if (DQ[i] == oele)
                {
                    printf("\nEnter new element : ");
                    scanf("%d", &nele);
                    DQ[i] = nele;
                    printf("\n%d updated for %d at index %d", oele, nele,i);
                    c++;
                }
            }
            if (c > 0)
                printf("\n%d elements updated.", c);
            else
                printf("\nElement not found");
        }
    }
    else if (queue_choice == 2)
    {
        if ((*rrt) == max)
        {
            printf("\nQueue is empty from right end.");
        }
        else
        {
            printf("\nEnter old element that you want to change : ");
            scanf("%d", &oele);
            for (i = (*frt); i >= (*rrt); i--)
            {
                if (DQ[i] == oele)
                {
                    printf("\nEnter new element : ");
                    scanf("%d", &nele);
                    DQ[i] = nele;
                    printf("\n%d updated for %d at index %d", oele, nele,i);
                    c++;
                }
            }
            if (c > 0)
                printf("\n%d elements updated.", c);
            else
                printf("\nElement not found");
        }
    }
    else
    {
        printf("\nPlease enter correct Queue number!.");
        goto x;
    }
}
 
void display(int DQ[], int *flt, int *rlt, int *frt, int *rrt)
{
    int queue_choice = 0, i;
    x:
    printf("\n1 For display Queue from Left end.");
    printf("\n2 For display Queue from Right end.");
    printf("\nEnter your choice : ");
    scanf("%d", &queue_choice);
    if (queue_choice == 1)
    {
        if ((*rlt) == -1)
        {
            printf("\nQueue is empty from left end.");
        }
        else
        {
            printf("\n");
            for (i = (*flt); i <= (*rlt); i++)
            {
                printf("\nQueue from left end : ");
                printf("%d ",DQ[i]);
            }
        }
    }
    else if (queue_choice == 2)
    {
        if ((*rrt) == max)
        {
            printf("\nQueue is empty from right end.");
        }
        else
        {
            printf("\n");
            {
            for (i = (*frt); i >= (*rrt); i--)
            {
                printf("Queue from right end : ");
                printf("%d ",DQ[i]);
            }
            }
         }
    }
    else
    {
        printf("\nPlease enter correct Queue number!.");
        goto x;
    }
}
int main()
{
    int DQ[max], fl = -1, rl = -1, fr = max, rr = max, *flp = &fl, *rlp = &rl, *frp = &fr, *rrp = &rr, choice;
    while (1)
    {
        printf("\n\n1 For insert ");
        printf("\n2 For delete ");
        printf("\n3 For modify ");
        printf("\n4 For display");
        printf("\n5 For exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(DQ, flp, rlp, frp, rrp);
            break;
        case 2:
            Delete(DQ, flp, rlp, frp, rrp);
            break;
        case 3:
            modify(DQ, flp, rlp, frp, rrp);
            break;
        case 4:
            display(DQ, flp, rlp, frp, rrp);
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
