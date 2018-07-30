#include<cstdio>
#include<utility>
using namespace std;
#define s scanf
#define p printf
typedef struct
{
    int price, weight,taken;
    double  price_per_weight;
}item;
item arr[100];
int main()
{
    int n,i,j,max_weight;
    while(s("%d",&n)==1)
    {
        for(i=1;i<=n;++i)
        {
            s("%d %d",&arr[i].price,&arr[i].weight);
            arr[i].price_per_weight=(double)(arr[i].price)/(double)(arr[i].weight);
        }
        for(i=1;i<n;++i)
        for(j=i+1;j<=n;++j)
        if(arr[i].price_per_weight<arr[j].price_per_weight)
        swap(arr[i].price_per_weight,arr[j].price_per_weight);

        s("%d",&max_weight);
        i=1;
        double profit=0;
    while(max_weight>0&&i<=n)
    {
        if(max_weight>arr[i].weight)
        {
            //profit+=arr[i].price;
            profit+=arr[i].weight*arr[i].price_per_weight;
            max_weight-=arr[i].weight;
            ++i;
        }
        else
        {
            profit+=(max_weight*arr[i].price_per_weight);
            max_weight=0;
        }
    }
    p("Max profit is: %lf\n\n",profit);
    }
    return 0;
}
/*
Input:
3
60 10
100 20
120 30
50
Output:
Max profit is: 240.000000
*/
