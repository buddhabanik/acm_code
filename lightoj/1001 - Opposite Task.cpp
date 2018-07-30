#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n ;
        if( n <= 10)
        {
            printf("0 %d\n",n);
        }
        else
        {
            printf("%d 10\n",n-10);
        }
    }
    return 0;
}
