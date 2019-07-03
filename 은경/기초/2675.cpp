#include<cstdio>
#include<cstring>
char sstr[21];
int main(void)
{
    int n,cnt;
    scanf("%d", &n);
    
    while (n--) {
        sstr[0]='\0';
        scanf("%d %s", &cnt, sstr);
        
        for(int i=0; sstr[i]!='\0'; i++) {
            for(int j=0; j<cnt; j++)
                printf("%c",sstr[i]);
        }
        printf("\n");
    }
    
    return 0;
}