#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack size
#define MAX_STACK_SIZE 100

// Stack operations
int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_STACK_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// int isEmpty()
// {
//     return top == -1;
// }

// The main function that returns value
// of a given postfix expression
int evaluatePostfix(char* exp)
{
    int i;

    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        // If the scanned character is an operand
        // (number here), push it to the stack.
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }

        // If the scanned character is an operator,
        // pop two elements from stack apply the operator
        else
        {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i])
            {
            case '+':
                push(val2 + val1);
                break;
            case '-':
                push(val2 - val1);
                break;
            case '*':
                push(val2 * val1);
                break;
            case '/':
                push(val2 / val1);
                break;
            }
        }
    }
    return pop();
}

// Driver code
int main()
{
    char exp[] = "231*+9-8+";
    printf("Postfix expression is : %s\n",exp);

    // Function call
    printf("postfix evaluation: %d", evaluatePostfix(exp));
    return 0;
}
