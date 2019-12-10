#include <stdio.h>

int ar[500];

void insert(int n, int value)
{
    if(ar[n]==0)
    {
        ar[n]=value;
    }
    else if( value > ar[n])
    {
        insert( 2*n+1, value);
    }
    else
        insert (2*n, value);
}

void print_inorder(int n)
{
    if(ar[n] != 0)
    {
        print_inorder( 2*n );
     //   if(root->left != NULL && root->right != NULL)
            printf("%d ",ar[n]);
        print_inorder( 2*n+1 );
    }
}

int main()
{

    int n;
    insert(1,6);
    insert(1,3);
    insert(1,10);
    insert(1,1);
    insert(1,5);
    insert(1,4);


    print_inorder(1);

    return 0;
}
