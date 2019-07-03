#include<cstdio>
int main(void)
{
    long long a,b,c,ans;
    scanf("%lld %lld %lld", &a, &b, &c);
    
    if(b>=c)
        printf("-1");
    else {
        ans=a/(c-b);
        printf("%lld", ans+1);
    }
    return 0;
}