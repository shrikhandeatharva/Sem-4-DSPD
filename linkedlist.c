#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void list_traverse(struct node *ptr){
    while(ptr!=NULL){
      printf("%d ",ptr->data);
      ptr = ptr->next;
    }
}

struct node * inseratstart(struct node * head,int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct node * insertinbetween(struct node * head,int data,int index){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node * insertatend(struct node * head,int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p = head;
    while(p->next != NULL)
    {
      p = p->next; 
    }
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct node * deletefirstnode(struct node * head)
{
    struct node * p = head;
    head = head->next;
    free(p);
    return head;
}

struct node * deletemiddlenode(struct node * head,int index)
{
    struct node * p = head;
    int j=0;
    while(j!=index-1){
       p=p->next;
       j++;
    }
    struct node * q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct node * deletelastnode(struct node * head)
{
    struct node * p = head;
    struct node * q = head->next;
    while(q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(p);
    return head;
}

int main(){
    struct node * head;
    struct node * second;
    struct node * third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
  
    head -> data = 7;
    head -> next = second;

    second ->data=66;
    second->next = third;

    third->data=69;
    third->next=NULL;

    printf("Linkedlist created :\n");
    list_traverse(head);  
    head = inseratstart(head,45);
    printf("\nAfter inserting a node at the beginning : \n");
    list_traverse(head);  
    head = insertinbetween(head,34,2);
    printf("\nAfter inserting new node in between :\n");
    list_traverse(head);
    head = insertatend(head,33);
    printf("\nAfter inserting node at the end is : \n");
    list_traverse(head);
    head = deletefirstnode(head);
    printf("\nAfter deleting first node : \n");
    list_traverse(head);
    head = deletemiddlenode(head,2); 
    printf("\nAfter deleting the middle node : \n");
    list_traverse(head);
    head = deletelastnode(head);
    printf("\nAfter deleting the last node : \n");
    list_traverse(head);
    return 0;
}