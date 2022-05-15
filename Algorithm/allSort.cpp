#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int ar[],int n)
{
    int i,j,tem;

    for(i=0; i<n-1; i++)
        for(j=0; j<n-1-i; j++)
             if(ar[j] > ar[j+1])
             {
                tem=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=tem;
             }
}

void selectionSort(int ar[], int n)
{

}



int main()
{
    int ar[100],n,i;
    scanf("%d",&n);
    for(i=0; i<n ;i++)
        scanf("%d",&ar[i]);
    bubbleSort(ar,n);
    for(i=0; i<n ;i++)
        printf("%d ",ar[i]);

    return 0;
}
