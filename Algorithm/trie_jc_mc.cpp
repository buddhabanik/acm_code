#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


struct node{

    bool endmark;
    struct node* next[26];
    node()
    {
        endmark=false;
        int i;
        for(i=0; i<26; i++)
            next[i]=NULL;
    }
};

void insert(struct node** root,char* ch)
{
    int i,l, id;
    struct node* cur=*root;
    l=strlen(ch);
    for(i=0; i<l ;i++)
    {
        id=ch[i]-'a';
        if(cur->next[id] == NULL)
            cur->next[id] = new node();
        cur=cur->next[id];
    }
    cur->endmark=true;
    return;
}


bool search(struct node** root, char* ch)
{
    int i,l,id;
    struct node* cur=*root;
    l=strlen(ch);
    for(i=0; i<l ;i++)
    {
        id=ch[i]-'a';
        if(cur->next[id] == NULL)
            return false;
        cur =cur->next[id];
    }
    return cur->endmark ;
}

void del(struct node* cur)
{
    int i;
  //  struct node* cur=*root;
    for(i=0; i<26; i++)
        if( cur->next[i])
        {
            del((cur->next[i]));
        }

    delete(cur);
}

void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main()
{
    struct node* root=new node();

    int n,i;
    scanf("%d",&n);
    getchar();
    char str[1000];
    for(i=0; i<n ;i++)
    {
        gets(str);
        insert(&root, str);
    }

    scanf("%d",&n);
    getchar();
    for(i=0; i<n ;i++)
    {
        gets(str);
        cout << search(&root, str) << endl;
    }
     cout << search(&root, "sust") << endl;
    del(root);
    cout << search(&root, "sust") << endl;

    return 0;
}
