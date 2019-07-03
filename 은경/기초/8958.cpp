#include<cstdio>
#include<cstring>
char str[82];
int main(void)
{
    int k,s,val,sum=0;
    scanf("%d", &k);
    
    while(k--) {
        scanf("%s", str);
        s=strlen(str);
        for (int i=0; i<s; i++) {
            if (str[i]=='O' && str[i-1]!='O')
                val=1;
            else if (str[i]=='O' && str[i-1]=='O')
                val+=1;
            else val=0;
            sum+=val;
        }
        printf("%d\n", sum);
        str[0]='\0'; sum=0;
    }
    return 0;
}