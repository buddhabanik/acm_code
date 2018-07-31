#include <stdio.h>

int g[200][200], le[100], vis[200], q[200];

int bfs(int v)
{
    int i,h=0,t=0, u;
    vis[0]=1;
    le[0]=0;
    q[h++]=0;


    while( h>t )
    {
        u=q[t++];
        vis[u]=1;
        for(i=0; i<v ;i++)
        {
            if(vis[i]== 0 && g[u][i] == 1)
            {
                if(le[u] == 0)
                    le[i]=1;
                else
                    le[i]=0;

                q[h++]=i;

            }
            else if(vis[i] ==1 && g[u][i] == 1)
            {
                if(le[u] == le[i])
                    return 0;
            }
        }
    }
    return 1;


}

int main()
{
    int e,v,i,j,res, n,m;

    while(scanf("%d",&v)==1)
    {

    if(v==0)
        break;

    scanf("%d",&e);
    for(i=0; i<e ; i++)
    {
        scanf("%d %d",&n,&m);
        g[n][m] = g[m][n] =1;
    }
    res = bfs(v);
    if(res)
        printf("BICOLORABLE.\n");
    else
        printf("NOT BICOLORABLE.\n");
    for(i=0; i<v ;i++)
    {
        vis[i]=0;
        le[i]=0;
        q[i]=0;
        for(j=0; j<v; j++)
            g[i][j]=0;
    }

    }
    return 0;
}
