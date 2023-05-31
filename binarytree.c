#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;// return the node created
}
// preorder traversing 
void pre_order(struct node * root)
{
    if(root!=NULL){
        printf("%d ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}
//postorder traversing
void post_order(struct node * root)
{
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d ",root->data);
    }
}
//inorder traversing
void in_order(struct node * root)
{
    if(root!=NULL){
        in_order(root->left);
        printf("%d ",root->data);
        in_order(root->right);
    }
}

int main()
{
    // creating nodes
    struct node * root = createnode(1);
    struct node * n1 = createnode(7);
    struct node * n2 = createnode(3);
    struct node * n3 = createnode(10);
    struct node * n4 = createnode(6);
    struct node * n5 = createnode(5);
  
    // linking nodes
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    //tp
    // printf("%d\n", root->left->data);
    // printf("%d\n", n1->left->data);

    printf("Preorder : ");
    pre_order(root);
    printf("\nPostorder : ");
    post_order(root);
    printf("\nInorder : ");
    in_order(root);

    return 0;
}