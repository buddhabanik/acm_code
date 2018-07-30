#include <bits/stdc++.h>
using namespace std;

int n,cont,f,vis[50],flag;
char c[100],dp[];
vector <char> num;

void rec()
{
    if( num.size() == n  && cont != f && flag == 0 )
    {
        for(int i=0; i<n ;i++)
            cout << num[i] ;
        cout << endl;
        ++cont;
        return ;
    }

    if( cont == f)
    {
        flag =1;
        return ;
    }
    else if( !flag )
    {
        for(int i=0; i<n ;i++)
        if( vis[i] == 0)
        {
            vis[i] =1;
            num.push_back(c[i]);
            rec();
            vis[i]=0;
            num.pop_back();
        }
    }
    else
        return ;
}

int main()
{
    int i,test,cas=0;
    cin >> test;
    while(test--)
    {

    cin >> n >> f;
    for(i=0; i<n ;i++)
        c[i] = 'A'+i ;
    c[i] = '\0';
    printf("Case %d:\n",++cas);
    cont = flag = 0;
    rec();
    num.clear();
    memset(vis, 0 , sizeof(vis));

    }
    return 0;

}
