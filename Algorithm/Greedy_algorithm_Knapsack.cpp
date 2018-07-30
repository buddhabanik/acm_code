#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define s scanf
#define p printf
typedef struct
{
    int value,weight;
}str;
str arr[100];
int main()
{
    int mat[101][101];
    int a,b,c,i,j,max_w,item;
    while(s("%d",&item)==1)
    {
        for(i=1;i<=item;++i)
        s("%d %d",&arr[i].value,&arr[i].weight);


        memset(mat,0,sizeof(mat));

        s("%d",&max_w);
        for(i=1;i<=item;++i)
            {
                for(j=1;j<=max_w;++j)
                {
                    a=mat[i-1][j];
                    c=j-arr[i].weight;
                    if(c>-1)
                    b=mat[i-1][c]+arr[i].value;
                    else
                    b=0;
                    if(a>b)
                        mat[i][j]=a;
                    else
                        mat[i][j]=b;
                }
            }
        p("Maximum profit is: %d\n\n",mat[item][max_w]);
    }
    return 0;
}
/*
Input:
4
10 5
40 4
30 6
50 3
10
Output:
Maximum profit is: 90
*/
