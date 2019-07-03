#include<cstdio>
int main(void)
{
    long long n;
    long long sum=0;
    scanf("%lld", &n);
    
    for(int i=1; i<n; i++)
        sum+=(n+1)*i;
    
    printf("%lld", sum);
    return 0;
}