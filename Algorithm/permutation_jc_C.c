#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,asign,vis[100], cont;
char ar[100];
char res[100];


void permu(int id)
{
    if(id==n)
    {
        int i;
//        char *ch =new char((res.size() + 5));
        char *ch =(char*)malloc((n+5)*sizeof(char));
        for( i=0; i<n; i++)
        {
            ch[i] = res[i];
        }
        ch[i]='\0';
        printf("%s\n",ch);
//        if(m.find(ch) == m.end())
//        {
//            m[ch]=asign++;
//            cout <<ch << endl ;
//            cont++;
//        }

        return;
    }
    else{
        int i;
        for(i=0; i<n; i++)
            if(vis[i]==0)
            {
                vis[i]=1;
                res[id] = ar[i];
                permu(id+1);
                vis[i]=0;
                //res.pop_back();
            }
    }

}

int main()
{
//    while( scanf("%d",&n)==1)
//    {
      int i;
      scanf("%d",&n);
      getchar();
      for(i=0; i<n ;i++)
        scanf("%c",&ar[i]);

       // memset(vis,0,sizeof(vis));
        permu(0);
  //  }


    return 0;
}

