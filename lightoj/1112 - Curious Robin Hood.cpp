#include <bits/stdc++.h>
using namespace std ;
#define inf 9999999
#define ll long long int
ll a[100005], m[300005];

void Min(ll indx , ll b , ll e )
{
    if( b == e )
    {
        m[indx] = a[b] ;
        return  ;
    }
    if( b < e )
    {
        ll l, r,  mid ;
        mid = (b+e)/2 ;
        Min( indx*2 , b , mid );
        Min(indx*2+1 , mid +1, e );
        l= m[indx*2];
        r= m[indx*2+1] ;
        m[indx] = l+ r  ;
    }
}

ll qu_min(ll n , ll b , ll e , ll i , ll j )
{
    if( i>e || b > j )
        return 0 ;
    if( b >= i && e <= j )
        return m[n] ;
    ll mid ,l , r ;
    mid= (b+e)/2 ;
    l = qu_min(2*n , b, mid , i , j );
    r=  qu_min( 2*n+1 , mid+1, e , i , j ) ;
    return l+r ;
}

void update( ll n , ll b , ll e ,ll i , ll value )
{
    if(i > e || b > i )
        return ;
    if( b == i && e == i )
    {
        if( value != 0 )
        m[n]= (m[n] + value) ;
        else
            m[n] = 0 ;
        return ;
    }
    ll mid, l, r ;
    mid = (b + e )/ 2 ;
    update( 2*n , b , mid , i , value);
    update( 2*n+1 , mid+1, e , i , value);
    m[n] = m[2*n] + m[2*n+1] ;
    return ;
}

int main()
{
//    freopen("input_loj.txt","r", stdin) ;
    ll n , i , q , tt, j , res, t , cas = 0  , indx , val ;
    scanf("%lld", &t) ;
    while(t--)
    {

   scanf("%lld %lld", &n , &q)  ;
    for( i= 1; i<= n ; i++ )
        scanf("%lld",&a[i]) ;

    Min( 1, 1, n ) ;
    printf("Case %lld:\n", ++cas);
   while(q--)
   {    scanf("%lld", &tt);
        if( tt == 1)
        {
            scanf("%lld", &i) ;
            printf("%lld\n", a[i+1]);
            a[i+1] = 0;
            update( 1, 1 , n , i+1 , 0 );
        }
        else if(tt == 2 )
        {
            scanf("%lld %lld", &i, &j) ;
            a[i+1] = (a[i+1] + j) ;
            update(1, 1, n , i+1, j  ) ;

        }
        else if( tt == 3)
        {
        scanf("%lld %lld", &i, &j) ;
        res = qu_min(1, 1, n , i+1, j+1 );
        printf("%lld\n", res );
        }
    }
    for(i=0; i<=n ; i++ )
    {
        a[i] = m[i] =  0;
    }

    }
    return 0;
}
