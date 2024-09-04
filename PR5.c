#include <stdio.h>

void push(int opeArray[], char infix, int *top) {
  *top += 1;
  opeArray[*top] = infix;
}

int operatorPriority(char operatorValue) {
  int priority;
  if (operatorValue == '*' || operatorValue == '/') {
    priority = 2;
  } else if (operatorValue == '+' || operatorValue == '-') {
    priority = 1;
  } else if (operatorValue == ')' || operatorValue == '(') {
    priority = 0;
  }

  return priority;
}

char pop(int opeArray[], int *top) {
  char operatorValue;
  operatorValue = opeArray[*top];
  *top -= 1;
  return operatorValue;
}

void main() {
  int opeArray[10], i = 0, x = -1, *top = &x;
  char infix[100], operatorValue;

  printf("Enter the Infix Expression : ");
  scanf("%s", infix);

  while (infix[i] != '\0') {
    if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' ||
        infix[i] == '/') {
      if (*top == -1) {
        push(opeArray, infix[i], top);
      } else {
        while (operatorPriority(opeArray[*top]) >= operatorPriority(infix[i]) &&
               opeArray[*top] != '(' && *top != -1) {
          operatorValue = pop(opeArray, top);
          printf("%c", operatorValue);
        }
        push(opeArray, infix[i], top);
      }
    } else if (infix[i] == '(') {
      push(opeArray, infix[i], top);
    } else if (infix[i] == ')') {
      while (opeArray[*top] != '(') {
        operatorValue = pop(opeArray, top);
        printf("%c", operatorValue);
      }
      operatorValue = pop(opeArray,top);
    } else if (infix[i] >= 'A' && infix[i] <= 'Z' ||
               infix[i] >= 'a' && infix[i] <= 'z') {
              printf("%c", infix[i]);
    }
    i += 1;
  }
  while (*top != -1) {
    operatorValue = pop(opeArray, top);
    // if (operatorValue != '(') {
    printf("%c", operatorValue);
    // }
  }
}
