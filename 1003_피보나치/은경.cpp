// 은경이 코드

#include<cstdio>
int dp[41][2];
int main(void)
{
    int t,x;
    scanf("%d", &t);
    dp[0][0]=1; dp[0][1]=0;
    dp[1][0]=0; dp[1][1]=1;
    
    for (int i=2; i<=41; i++) {
        dp[i][0]=dp[i-1][0]+dp[i-2][0];
        dp[i][1]=dp[i-1][1]+dp[i-2][1];
    }
    
    while(t--) {
        scanf("%d", &x);
        printf("%d %d\n", dp[x][0], dp[x][1]); //o1
    }
    return 0;
}
