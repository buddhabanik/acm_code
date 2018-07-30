#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,r,i,res,ca=0,test;

    cin >> test;
    while( test--)
    {

    cin >> n >> r;
    if(r > n/2 )
        r = n-r;

    res = 1;
    for(i=1; i<= r ;i++)
    {
        res *= n - r +i ;
        res /= i;
        if( res > 1000003)
            res %= 1000003;
    }

    printf("Case %lld: %lld\n",++ca, res );

    }

    return 0;
}
