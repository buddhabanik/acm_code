#include <bits/stdc++.h>
using namespace std;

int n ,a[500][500],dp[500][500];


 int rec( int i, int j)
{
    if( i < 0 || i>=(2*n-1) || j < 0 || j >= (2*n-1) || a[i][j] == 0 )
        return 0;

    if( dp[i][j] != 0 )
        return dp[i][j];

    if(i < n-1  )
    {
    int ret= -999;
    ret =max( ret, a[i][j] +  rec(i+1, j) ) ;

    ret =max( ret, a[i][j] + rec(i+1, j-1) )  ;

    return dp[i][j] = ret;

    }

    else
    {
    int ret= -999;
    ret =max( ret, a[i][j] +  rec(i+1, j) ) ;
    ret =max( ret, a[i][j] + rec(i+1, j+1) )  ;
    return dp[i][j] = ret;
    }


}


int main()
{

    int i,j,p,test,ca=0;
    cin >> test;

    while( test -- )
    {

    cin >> n ;

    p= n-1;
    for(i=0; i< n; i++)
    {
        for(j=p; j< n ; j++)
           cin >> a[i][j] ;
        p--;
    }

    p = 1;
    for(i=n ; i<(2*n - 1) ;i++)
    {
        for(j=p; j< n ; j++)
            cin >> a[i][j] ;
        p++;
    }

     printf("Case %d: %d\n",++ca,rec(0,n-1));

    for(i=0; i < 2*n ;i++)
        for(j=0; j< 2*n ; j++)
       {
        a[i][j] = 0;
        dp[i][j] = 0;
       }

    }

    return 0;
}
