#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node *left,*right;
};

struct node* insert(struct node* root, int value)
{
    if( root == NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->left= newnode->right= NULL;
        return newnode;
    }

    else if(value < root->data)
        root->left=insert(root->left,value);
    else
        root->right=insert(root->right, value);

    return root;
}

int search(struct node* root, int value)
{
    if(root==NULL)
        return 0;
    else if(root->data == value)
        return 1;
    else if(value < root->data)
        search(root->left, value);
    else if(value > root->data)
        search(root->right,value);
}

void print_preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_inorder(struct node* root)
{
    if(root != NULL)
    {
        print_inorder(root->left);
     //   if(root->left != NULL && root->right != NULL)
            printf("%d ",root->data);
        print_inorder(root->right);
    }
}
void print_postorder(struct node* root)
{
    if(root != NULL)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    struct node* root=NULL;

    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);
    root=insert(root,10);
    root=insert(root,25);

    printf("preorder =>  ");   print_preorder(root);   printf("\n");
    printf("inorder =>   ");   print_inorder(root);    printf("\n");
    printf("postorder => ");   print_postorder(root); printf("\n");

    printf("%d \n",search(root,34));


    return 0;
}
