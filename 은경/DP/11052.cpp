#include<cstdio>
#define max(a,b) a>b?a:b
int p[10001];
int dp[10001];
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
        scanf("%d", &p[i]);
    
    dp[0]=p[0]=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++)
            dp[i]=max(dp[i],dp[i-j]+p[j]);
    }
    
    printf("%d", dp[n]);
    
    return 0;
}