#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

int pop() {
    if (top >= 0)
        return stack[top--];
    return 0;
}

int main() {
    char exp[MAX];
    int i;
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i]))
            push(exp[i] - '0');
        else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    printf("Result: %d\n", pop());
    return 0;
}
