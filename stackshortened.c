#include<stdio.h>
#include<stdlib.h>

#define SIZE 4
int top = -1,arr[SIZE];

void push(int n){
    int x = n;
    if(top == SIZE-1){
      printf("\nOverflow i.e stack is full");
    }
    else{
        top = top +1;
        arr[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("Underflow i.e Stack is empty");
    }
    else{
        printf("\nPopped element is : %d",arr[top]);
        top = top - 1;
    }
}

void display()
{
    if(top == -1)
    {
        printf("Empty stack");
    }
    else{
        printf("\nElements in the stack are : " );
        for(int i = top;i>=0;--i)
        {
            printf("%d ",arr[i]);
        }
    }
}

void main()
{
    push(4);
    push(7);
    push(3);
    display();
    pop();
    pop();
    display();
}