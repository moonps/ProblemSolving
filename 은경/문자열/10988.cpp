#include<cstdio>
#include<cstring>
char ar[102];
int main(void)
{
    int s1,s2,check=0;
    scanf("%s", ar);
    s1=strlen(ar);
    s2=s1/2;
    
    for (int i=0; i<s2; i++) {
        if (ar[i] == ar[s1-i-1]) check++;
    }
    
    if (check==s2) printf("1");
    else printf("0");
    return 0;
}