#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
int display();
void insertion();
void deletion();
void main()
{
    while(1)
    {
        int choice;
        printf("enter your choice\n 1.Display\n2.Insertion\n3.deletion\n4.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
              display();
              break;
            case 2:
              insertion();
              break;
            case 3:
              deletion();
              break;
            case 4:
              return;
            default:
               break;    
        }
    }
}
//insert a node into the tree and return the root
struct node *insert(struct node *root,struct node *newNode)
{
    if(root==NULL)
       root=newNode;
    else if(root->data > newNode->data)
       root->left=insert(root->left,newNode);
    else
       root->right=insert(root->right,newNode);
    return root;
}
void insertion()
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("element:");
    scanf("%d",&newNode->data);
    newNode->left=newNode->right=NULL;
    root=insert(root,newNode);
    display();
}
//return the smallest node in a tree
struct node *find_min(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
struct node *delete(struct node *root,int value)
{
    if(root==NULL)
    {
        printf("not found\n");
        return root;
    }
    //find the node,while keeping track of the path taken to reach it
    struct node *temp;
    if(value<root->data)
    {
        root->left=delete(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=delete(root->right,value);

    }
    else{
        //reached the node to delete
        //if only one child
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
       
        {
            temp=root->left;
            free(root);
            return temp;
        }
        //if the node has two children
        //replace the data in the node with the data of its inorder successor
        root->data=find_min(root->right)->data;
        //delete the inorder successor,also maintaining the structure of the tree
        root->right=delete(root->right,root->data);    
    }
    return root;
}
void deletion()
{
    int value;
    printf("enter the node to delete:");
    scanf("%d",&value);
    root=delete(root,value);
    display();
}
//perform all three traversal to display the tree
//root->left->right
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ->",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ->",root->data);
}
int display()
{
    if(root==NULL)
    {
        printf("tree is empty");
        return 1;
    }
    printf("preorder:");
    preorder(root);
    printf("inorder:");
    inorder(root);
    printf("postorder:");
    postorder(root);
    return 0;
}