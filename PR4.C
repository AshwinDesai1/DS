#include <stdio.h>

int operatorPriority(char operatorValue) {
  int priority;
  if (operatorValue == '*' || operatorValue == '/') {
    priority = 2;
  } else if (operatorValue == '+' || operatorValue == '-') {
    priority = 1;
  }
  return priority;
}

void push(int opeArray[], int *top, char operatorValue) {
  *top += 1;
  opeArray[*top] = operatorValue;
}

char pop(int opeArray[], int *top) {
  char value = opeArray[*top];
  *top -= 1;
  return value;
}

void main() {

  int opeArray[50], i = 0, x = -1, *top = &x;
  char ch[20], operatorPop;

  printf("Enter the Infix Expression :");
  scanf("%s", ch);

  while (ch[i] != '\0') {

    if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
      if (*top == -1) {
        push(opeArray, top, ch[i]);
      } else {
        while (operatorPriority(opeArray[*top]) >= operatorPriority(ch[i]) && *top >= 0) {
          operatorPop = pop(opeArray, top);
          printf("%c", operatorPop);
        } 
          push(opeArray, top, ch[i]);
        
      }
    } else if (ch[i] >= 'a' && ch[i] <= 'z' || ch[i] >= 'A' && ch[i] <= 'Z') {
      printf("%c", ch[i]);
    }
    i++;
  }
  while (*top != -1) {
    operatorPop = pop(opeArray, top);
    printf("%c", operatorPop);
  }
}
