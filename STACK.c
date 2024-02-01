//implement a stack using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(int);
int pop();
void display();
int main()
{
    int ch, val;
    printf("\n1. Push in stack");
    printf("\n2. Pop from stack");
    printf("\n3. Display stack");
    printf("\n4. Exit");
    do
    {
        printf("\n\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to be pushed:");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1)
                printf("\n The number deleted is : %d", val);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExit");
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (ch != 4);
    return 0;
}
void push(int val)
{
    if (top == MAX - 1)
        printf("\nStack is full");
    else
    {
        top++;
        stack[top] = val;
    }
}
int pop()
{
    int val;
    if (top == -1)
    {
        printf("\nStack is empty");
        return -1;
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}
void display()
{
    int i;
    if (top == -1)
        printf("\nStack is empty");
    else
    {
        printf("\nStack is...\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}


