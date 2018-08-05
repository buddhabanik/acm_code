#include <bits/stdc++.h>
using namespace std;

void find_All_Subset(vector<int>& v,  vector<vector<int> >& res,  vector<int>& subset,  int idx)
{
    int i;
    for(i=idx ; i<v.size(); i++)
    {
        subset.push_back(v[i]);
        res.push_back(subset);
        find_All_Subset(v,res,subset,i+1);
        subset.pop_back();
    }
    return;
}

vector<vector<int> > subsets(vector<int>& v)
{
    vector<vector<int> >res;
    vector<int>subset;
    res.push_back(subset);
    find_All_Subset(v, res, subset,0);
    return res;
}

int main()
{
    int i,j,n,x;
    vector<int> v;
    scanf("%d",&n);
     for(i=0; i<n ;i++)
     {
         scanf("%d",&x);
         v.push_back(x);
     }

     vector<vector<int> >res;
     res = subsets(v);

    cout <<"Total size of power set = "<<res.size()+1 << endl;
    cout << "{} "<< endl;
    for(i=1; i<res.size() ;i++)
    {
        for(j=0; j<res[i].size() ;j++)
            cout << res[i][j] << " ,";
      cout << endl;
    }

    return 0;
}
