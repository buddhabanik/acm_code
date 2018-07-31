#include <cstdio>

using namespace std;

int dp[1000][1000];

int nCr(int n,int r)
{
    if(dp[n][r] != -1)
        return dp[n][r];
    if(r == 1)
        return n;
    if(n==r)
         return 1;
    else
    {
        dp[n][r] = nCr(n-1, r ) + nCr(n-1 , r-1);
        return dp[n][r];
    }
}

int main()
{
    int i,j,n,r, res;

    scanf("%d %d",&n,&r);
    for(i=0; i<100; i++)
        for(j=0; j<100 ; j++)
            dp[i][j] = -1;


    res=nCr(n,r);
    printf("%d",res);

    return 0;
}
