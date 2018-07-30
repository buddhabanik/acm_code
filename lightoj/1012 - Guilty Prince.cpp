//undirected graph
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
queue<int>Q;
int arr[1000][1000],dis[1000],vis[1000];
void bfs(int start,int end)
{
    int i,u;
    while(!Q.empty())
    Q.pop();
    Q.push(start);
    vis[start]=1;
    dis[start]=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=1;i<=end;++i)
        if(vis[i]==0&&arr[u][i]==1)
        {
            vis[i]=1;
            dis[i]=dis[u]+1;
            Q.push(i);
        }
    }
    return ;
}
int main()
{
    int p,d,i,m,n,x,y, test ;
    cin >> test ;

    while( test--)
    {
        scanf("%d %d",&p,&d) ;
        memset(arr,0,sizeof(arr));
        memset(dis,-1,sizeof(dis));
        memset(vis,0,sizeof(vis));
        for(i=0;i<d;++i)
        {
            scanf("%d %d",&m,&n);
            arr[m][n]=arr[n][m]=1;
        }
        bfs(1,p);
        printf("Level for all nodes is: ");
            for(i=1;i<=p;++i)
            printf(" %d",dis[i]);
        printf("\n\n");
    }
    return 0;
}
