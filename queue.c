#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int front = -1, rear = -1, queue[SIZE];

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\nPerform operations on the queue:");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.End");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice!");
        }
    }
}

void enqueue()
{
    int x;
    if (rear == SIZE - 1)
    {
        printf("\nQueue is full! Cannot enqueue.");
    }
    else
    {
        printf("\nEnter the element to be enqueued: ");
        scanf("%d", &x);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = x;
        printf("Enqueued element: %d", x);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty! Cannot dequeue.");
    }
    else
    {
        printf("\nDequeued element: %d", queue[front]);
        front++;

        if (front > rear)
        {
            // Reset the queue
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nElements present in the queue: \n");
        for (int i = front; i <= rear; ++i)
            printf("%d\n", queue[i]);
    }
}
