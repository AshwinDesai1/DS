#include <stdio.h>
#include <stdlib.h>
#define max 5
void insert(int DQ[], int *f, int *r)
{
    int ele;
    if (*r == max - 1 && *f == 0)
    {
        printf("\nQueue is full.");
    }
    else if ((*r == *f - 1))
    {
        printf("\nQueue is full.");
    }
    else
    {
        printf("\nEnter element : ");
        scanf("%d", &ele);
        if (*f == -1 && *r == -1)
        {
            (*f) = (*r) = 0;
            DQ[*r] = ele;
        }
        else if ((*r) == max - 1 && (*f) > 0)
        {
            (*r) = 0;
            DQ[*r] = ele;
        }
        else
        {
            (*r)++;
            DQ[*r] = ele;
        }
        printf("\n%d inserted at index %d .", ele, *r);
    }
}
void Delete(int DQ[], int *f, int *r)
{
    int rele;
    if (*r == -1 && *f == -1)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        if (*f == *r)
        {
            rele = DQ[*f];
            (*f) = (*r) = -1;
        }
        else if ((*f) == max - 1 && (*r) != max - 1)
        {
            rele = DQ[*f];
            *f = 0;
        }
        else
        {
            rele = DQ[*f];
            (*f)++;
        }
        printf("\n%d removed.", rele);
    }
}
void modify(int DQ[], int *f, int *r)
{
    int ele, nele, i;
    if (*r == -1 && *f == -1)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nEnter element old element that you want to change : ");
        scanf("%d", &ele);
        for (i = *f; i < max; i++)
        {
            if (DQ[i] == ele)
            {
                printf("\nEnter new element : ");
                scanf("%d", &nele);
                DQ[i]=nele;
                printf("\n%d updated for %d at index %d.",ele,nele,i);
                break;
            }
            if (i == max - 1 && *r != max - 1)
            {
                i = -1;
            }
        }
    }
}
int main()
{
    int DQ[max], fl = -1, rl = -1, *f = &fl, *r = &rl, choice;
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
            insert(DQ, f, r);
            break;
        case 2:
            Delete(DQ, f, r);
            break;
        case 3:
            modify(DQ, f, r);
            break;
        case 4:
            // display(DQ, flp, rlp, frp, rrp);
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
