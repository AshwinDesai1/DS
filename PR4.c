#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5


void push(int stack[],int *top1,int *top2,char ch[]){
    int element,index;
    if((*top1+1) == *top2){
        printf("Stack is overflow\n");
    }else{
        printf("Enter Element : ");
        scanf("%d",&element);
        
        if((strcmp(ch,"stack1")) == 0){
            index = ++(*top1);
        }else{
            index = --(*top2);
        }
        
        stack[index] = element;
        printf("Element %d is push at %d position\n",element,index);
    }
}

void pop(int stack[],int *top,char ch[]){
    int index;
    if((strcmp(ch,"stack1")) == 0){
        stack[*top] = 0;
        index = *top;
        *top-=1;
    }else{
        stack[*top] = 0;
        index = *top;
        *top+=1;
    }
    printf("Element is pop from %d position",index);
}

void peep(int stack[],int *top){
    printf("Top element is %d\n",stack[*top]);
}

int searchIndex(int stack[],int start,int end,int element){
    int i;
    for(i=start;i<=end;i++){
        if(stack[i] == element){
            return i;
        }
    }
    return -1;
}

void modify(int stack[],int *top,char ch[]){
    int oldElement,newElement,index;
    printf("Enter Old Element : ");
    scanf("%d",&oldElement);
    printf("Enter new Element : ");
    scanf("%d",&newElement);
    if((strcmp(ch,"stack1"))==0){
        index = searchIndex(stack,0,*top,oldElement);
    }else{
        index = searchIndex(stack,*top,MAX-1,oldElement);
    }
    if(index == -1){
        printf("Element Not found\n");
    }else{
        stack[index] = newElement;
    }
}

void display(int stack[],int *top,char ch[]){
    int i;
    printf("Elements : ");
    if((strcmp(ch,"stack1")) == 0){
        for(i=0;i<=*top;i++){
            printf("%d   ",stack[i]);
        }
    }else{
        for(i=*top;i<MAX;i++){
            printf("%d   ",stack[i]);
        }
    }
    printf("\n");
}



void main(){
    int stack[MAX];
    int x1=-1,x2=MAX , *top1 = &x1,*top2 = &x2;
    int choice;
    
    while(1){
        printf("\n1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Peep Stack 1\n");
        printf("6. Peep Stack 2\n");
        printf("7. Modify Stack 1\n");
        printf("8. Modify Stack 2\n");
        printf("9. Display Stack 1\n");
        printf("10. Display Stack 2\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            push(stack,top1,top2,"stack1");
            break;
            
            case 2:
            push(stack,top1,top2,"stack2");
            break;
            
            case 3:
            if(*top1 == -1){
                printf("Stack 1 is underflow\n");
            }else{
                pop(stack,top1,"stack1");
            }
            break;
            
            case 4:
            if(*top2 == MAX){
                printf("Stack 2 is underflow\n");
            }else{
                pop(stack,top2,"stack2");
            }
            break;
            
            case 5:
            if(*top1 >= 0){
                peep(stack,top1);
            }else{
                printf("No element is available");
            }
            break;
            
            case 6:
            if(*top2 < MAX){
                peep(stack,top2);
            }else{
                printf("No element is available");
            }
            break;
            
            case 7:
            if(*top1 >= 0){
                modify(stack,top1,"stack1");
            }else{
                printf("No element is available");
            }
            break;
            
            case 8:
            if(*top2 < MAX){
                modify(stack,top2,"stack2");
            }else{
                printf("No element is available");
            }
            break;
            
            
            case 9:
            display(stack,top1,"stack1");
            break;
            
            case 10:
            display(stack,top2,"stack2");
            break;
            
            case 11:
            exit(0);
            break;
            
            default:
            printf("Eneter Valid Choice . \n");
            break;
        }
        
    }
}
