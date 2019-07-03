#include<cstdio>
long dp[91][2];
int main(void)
{
    int n;
    long ans;
    scanf("%d", &n);
    
    dp[1][0]=0; dp[1][1]=1;
    dp[2][0]=1; dp[2][1]=0;
    
    for(int i=3; i<=n; i++) {
        dp[i][0]=dp[i-2][0]*2+dp[i-2][1];
        dp[i][1]=dp[i-2][0]+dp[i-2][1];
    }
    
    ans=dp[n][0]+dp[n][1];
    printf("%ld", ans);
    return 0;
}