#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t ,x,sum,ca=0,i , n;

    cin >> t;
    while( t--)
    {
        cin >> n;
        sum =0;
        for(i=0; i<n ;i++)
        {
            cin >> x;
            if( x >= 0)
               sum += x;
        }

    printf("Case %d: %d\n",++ca,sum);
   }

    return 0;
}
