#include<cstdio>
#include<algorithm>
using namespace std;
int dp[501][501];
int main(void)
{
    int n,big=0;
    scanf("%d", &n);
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=i; j++)
            scanf("%d", &dp[i][j]);
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (j==1) dp[i][1]+=dp[i-1][1];
            else if (j==i) dp[i][j]+=dp[i-1][j-1];
            else
                dp[i][j]=dp[i][j]+max(dp[i-1][j-1], dp[i-1][j]);
            
            if (big<dp[i][j]) big=dp[i][j];
        }
    }
    printf("%d", big);
    return 0;
}