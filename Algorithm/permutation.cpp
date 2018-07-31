#include <bits/stdc++.h>
using namespace std;

int n,asign,vis[100], cont;
char ar[100];
vector<char>res;
map<string,int>m;


void permu(int id)
{
    if(id==n)
    {
        int i;
        char *ch =new char((res.size() + 5));
        for( i=0; i<res.size(); i++)
        {

            ch[i] = res[i];
        }
        ch[i]='\0';
        //if there is any multiple same character
        if(m.find(ch) == m.end())
        {
            m[ch]=asign++;
            cout <<ch << endl ;
            cont++;
        }

        return;
    }
    else{
        for(int i=0; i<n; i++)
            if(vis[i]==0)
            {
                vis[i]=1;
                res.push_back(ar[i]);
                permu(id+1);
                vis[i]=0;
                res.pop_back();
            }
    }

}

int main()
{
    while(cin >> n)
    {
      for(int i=0; i<n ;i++)
        cin>>ar[i];
        asign=0;
        m.clear();
        res.clear();
        memset(vis,0,sizeof(vis));
        permu(0);
        cout << asign << endl;

    }


    return 0;
}
