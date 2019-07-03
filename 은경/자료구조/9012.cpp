#include<cstdio>
#include<cstring>
char st[51];
char temp[51];
int main(void)
{
    int t,k,tot;
    scanf("%d", &t);
    
    while(t--) {
        temp[0]='\0'; st[0]='\0'; tot=0;
        scanf("%s", temp);
        k=strlen(temp);
        
        for (int i=0; i<k; i++) {
            if(temp[i]=='(') st[tot++]='(';
            else if (temp[i]==')' && st[(tot-1)]=='(') st[--tot]='\0';
            else st[tot++]=')';
        }
        if(st[0]=='\0') printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
