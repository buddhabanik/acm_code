#include <bits/stdc++.h>
using namespace std;

long long int n,r,cont,a[1000000];
vector <int> num;

void rec(int sum)
{
    if(sum == n && num.size() == r)
    {
        ++cont;

        if(cont > 1000000007)
            cont %= 1000000007;

        return ;
    }
    if( sum > n || num.size() > r)
        return ;
    else
    {
        for(int i=0; i<=n ;i++)
        {
            num.push_back(a[i]);
            sum += a[i] ;
            rec(sum);
            sum -= a[i] ;
            num.pop_back();
        }
    }
}

int main()
{
    long long int i,t,ca=0;
    cin >> t;
    while(t--)
    {
    cin >> n >> r;
    for(i=0; i<=n ; i++)
        a[i]=i;
    rec(0);
    printf("Case %lld: %lld\n",++ca,cont);
    cont=0;
    }

    return 0;
}
