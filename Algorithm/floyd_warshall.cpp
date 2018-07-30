#include <cstdio>
using namespace std;

#define s scanf
#define p printf
int node,dist[50][50],path[50][50];

void initialize(void)
{
    for(int i=1; i<=node; ++i)
        for(int j=1; j<=node; ++j)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=100000;
            path[i][j]=0;
        }
    return ;
}

void floyd_warshall(void)
{
    int i,j,k,temp;
    for(k=1; k<=node; ++k)
    {
        for(i=1; i<=node; ++i)
        {
            for(j=1; j<=node; ++j)
            {
                temp=dist[i][k]+dist[k][j];
                if(dist[i][j]>temp)
                {
                    dist[i][j]=temp;
                    path[i][j]=path[k][j];
                }
            }
        }
    }
    return ;
}

void print_path(int a,int b)
{
    if(path[a][b]==a)
    {
        p(" %d ",path[a][b]);
        return ;
    }
    else if(path[a][b]==0)
    {
        p("No path.\n");
        return ;
    }
    else
    {
        print_path(a,path[a][b]);
        p(" %d ",path[a][b]);
        return ;
    }
}
int main()
{
    int i,k,j,a,b,edge,cost,start,end;
    while(s("%d %d",&node,&edge)==2)
    {
        initialize();
        for(i=1; i<=edge; ++i)
        {
            s("%d %d %d",&a,&b,&cost);
            dist[a][b]=cost;
        }
        for(i=1; i<=node; ++i)
        {
            for(j=1; j<=node; ++j)
            {
                if((i!=j)&&(dist[i][j]!=10000))
                    path[i][j]=i;
            }
        }
        //calling_floyd_warshall_function
        floyd_warshall();


        while(s("%d %d",&start,&end)==2)
        {
            print_path(start,end);
            p(" %d\n",end);
        }
    }
    return 0;
}
/*Sample Input:
3 5
1 3 11
1 2 4
2 3 2
3 1 3
2 1 6
1 3
3 1
2 1
3 2
2 3
Sample Output:
*/
