#include<cstdio>
#include<algorithm>
int dp[1002];
int main(void)
{
    int n;
    scanf("%d", &n);
    
    dp[1]=1;
    dp[2]=3;
    
    for (int i=3; i<=n; i++)
        dp[i]=(dp[i-1]+dp[i-2]*2)%10007;
    
    printf("%d", dp[n]);
    return 0;
}