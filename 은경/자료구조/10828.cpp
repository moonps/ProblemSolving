#include<iostream>
#include<cstdio>
int st[10001], tot;
int main(void)
{
    int t,x;
    char ord[5];
    scanf("%d", &t);
    
    while(t--)
    {
        ord[0]='\0';
        scanf("%s", ord);
        
        if(ord[0]=='p') {
            if(ord[1]=='u') {
                scanf(" %d", &x);
                st[tot++] = x;
            } else if (ord[1]=='o') {
                if (tot != 0)
                    printf("%d\n", st[--tot]);
                else printf("-1\n");
            }
        } else if (ord[0]=='s') {
            printf("%d\n", tot);
        } else if (ord[0]=='e') {
            if (tot == 0) printf("1\n");
            else printf("0\n");
        } else if (ord[0]=='t') {
            if (tot != 0) printf("%d\n", st[(tot-1)]);
            else printf("-1\n");
        }
    }
    return 0;
}