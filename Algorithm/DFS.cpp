//dfs_by_sabir_sir
//directed graph-----
    /*In this program......
         'w' means not visited
         'g' means visiting
         'b' means already visited
    */
#include<stdio.h>
#include<string.h>
using namespace std;
#define s scanf
#define p printf
int i,node,edge,start,end,dist[100],par[100],mat[100][100],time;
char color[100];
void initialize(void)
{
    time=0;
    memset(mat,0,sizeof(mat));
    for(i=1;i<=edge;++i)
    {
        par[i]=0;
        color[i]='w';
        //dist[i]=100000;
    }
}
void dfs(int v)
{
    int adj;
    color[v]='g';
    dist[v]=++time;
    for(adj=1;adj<=node;++adj)
    {
        if(mat[v][adj]==1)
        if(color[adj]=='w')
        {
            color[adj]='g';
            par[adj]=v;
            dfs(adj);
        }
    }
    color[v]='b';
}
void path_print(int v)
{
    if(start==v)
    p("%d",v);
    else if(par[v]==0)
    p("No path\n");
    else
    {
        path_print(par[v]);
        p(" %d",v);
    }
    return ;
}
int main()
{
    int a,b;
    while(s("%d %d",&node,&edge)==2)
    {
        initialize();
        for(i=1;i<=edge;++i)
        {
            s("%d %d",&a,&b);
            mat[a][b]=1;
        }
        s("%d %d",&start,&end);
        dfs(start);
        path_print(end);
        p("\n\n");
    }
    return 0;
}
/*
Input:
6 7
1 2
2 3
1 4
2 5
3 6
6 5
5 4
1 6

Output:
1 2 3 6
Input:
7 7
1 2
2 3
1 4
2 5
3 6
6 5
5 4
1 7
Output:
No path
*/
