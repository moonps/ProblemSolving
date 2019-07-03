#include<cstdio>
#define mod 10007
long long dp[1000][11];
int main(void)
{
    int n,sum=0,ans;
    scanf("%d", &n);
    
    for(int i=0; i<10; i++) dp[1][i]=1;

    for(int i=2; i<=n; i++) {
        dp[i][0]=1;
        for(int j=1; j<=9; j++) {
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
        }
    }

    for(int i=0; i<10; i++)
        sum=(sum+dp[n][i])%10007;
    printf("%d", sum%mod);
    
    return 0;
}