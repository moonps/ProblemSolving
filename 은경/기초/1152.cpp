#include<cstdio>
#include<cstring>
char str[1000001];
int main(void)
{
    int cnt=1,k;
    scanf("%[^\n]s", str);
    k=strlen(str);
    
    if(str[0]==' ') cnt--;
    for (int i=0; i<k; i++) {
        if (str[i] == ' ' && str[i+1]!='\0')
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}