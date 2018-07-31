#include <stdio.h>
#include <string.h>

char* f(char ch[])
{

    int i;

//    char *c=new char( strlen(ch)+5);
    char *c=(char*)malloc((strlen(ch)+5)*sizeof(char));
    for(i=0; i<strlen(ch); i++)
        c[i] = ch[i];
    c[i] ='\0';
    printf("new %s\n",c);
    return c;

}

int main()
{
    char *r;
    r=f("sagor");
    printf("main %s\n",r);
    return 0;
}
