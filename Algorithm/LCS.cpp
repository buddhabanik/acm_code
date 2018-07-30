//Longest_common_subsequence
#include<cstdio>
#include<cctype>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
char x[10] ,y[10];
void print_func(int a, int b);
int mat[100][100],c[100][100];
int main()
{
    int a,b,i,j;
    while(scanf(" %s %s",x,y)!=EOF)
    {
        a=strlen(x);
        b=strlen(y);
        memset(mat,0,sizeof(mat));
        for(i=1;i<=a;++i)
        {
            for(j=1;j<=b;++j)
            {
                if(x[i-1]==y[j-1])
                {
                    mat[i][j]=mat[i-1][j-1]+1;
                    c[i][j]='d';
                }
                else if(mat[i-1][j]>mat[i][j-1])
                {
                    mat[i][j]=mat[i-1][j];
                    c[i][j]='u';
                }
                else
                {
                    mat[i][j]=mat[i][j-1];
                    c[i][j]='l';
                }

            }
        }
        printf("*****\nNumber of total subseqence is: %d\nLongest_common_subsequence is : ",mat[a][b]);
        print_func(a,b);
        printf("\n*****\n\n");
    }
    return 0;
}
void print_func(int i, int j)
{
    if(i==0||j==0)
    return ;
    if(c[i][j]=='d')
    {
        print_func(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(c[i][j]=='l')
    {
        print_func(i,j-1);
    }
    else
    {
        print_func(i-1,j);
    }
    return ;
}

/*
Input:
BDAB BCAB
Output:
BAB
*/
