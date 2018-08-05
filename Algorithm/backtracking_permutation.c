#include <stdio.h>

#define pf printf

int ar[1000],vis[1000],res[1000],n, r;

void permu(int id)
{
    int i;
    if(id == r)
    {
        for(i=0; i<r ; i++)
        {
            printf("%d ",res[i]);
        }
        pf("\n");
        return ;
    }

    for(i=0; i<n ;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            res[id]=ar[i];
            permu(id+1);
            vis[i]=0;
        }
    }

}

int main()
{
    int i;
    scanf("%d %d",&n,&r);
    for(i=0; i<n ; i++)
    {
        scanf("%d",&ar[i]);
    }
    permu(0);

}
