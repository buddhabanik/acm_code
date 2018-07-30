//Edit_Distance.....
#include<cstdio>
#include<cctype>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define s scanf
#define p printf
int main()
{
    char x[10],y[10],c[10][10];
    int mat[10][10],i,j,a,b;
    while(s("%s %s",x,y)==2)
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
                        mat[i][j]=mat[i-1][j-1];
                        c[i][j]='D';
                    }
                    else if(mat[i-1][j]>mat[i][j-1])
                    {
                        mat[i][j]=mat[i][j-1]+1;
                        c[i][j]='L';
                    }
                    else
                    {
                        mat[i][j]=mat[i-1][j]+1;
                        c[i][j]='U';
                    }
                    //printf(" %c ",c[i][j]);
                }
                    //printf("\n");
        }
        p("%d\n\n",mat[a][b]);
    }
    return 0;
}
/*
GAMBOL GUMBO
3
ABDULLAH ABDALLAH
2
//ABCACABDC BACADCBAC
5
*/
