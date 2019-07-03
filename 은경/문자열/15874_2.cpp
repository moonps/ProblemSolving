#include<stdio.h>
#include<ctype.h>
char str[100010];
int main(void)
{
    int k,n;
    scanf("%d %d\n", &k, &n);
    k%=26;
    
    fgets(str,n+1, stdin);
    for(int i=0; i<n; i++) {
        if(str[i]>='a' && str[i]<='z') {
            str[i]=(str[i]-'a'+k)%26+'a';
            
        } else if (str[i]>='A' && str[i]<='Z') {
            str[i]=(str[i]-'A'+k)%26+'A';
        }
    }
    for(int i=0; i<n; i++)
        printf("%c", str[i]);
    
    return 0;
}