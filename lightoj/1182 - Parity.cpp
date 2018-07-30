#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , t , cont , p, cas =0 ;
    cin >> t ;
    while( t-- )
    {
        cin >> n ;
        cont = 0;
        while( n > 0)
        {
            p = n %2 ;
            if( p == 1)
                ++cont;
            n /= 2;
        }

        if( cont %2 == 1 )
            printf("Case %d: odd\n", ++cas);
        else
            printf("Case %d: even\n", ++cas);

    }
    return 0;
}
