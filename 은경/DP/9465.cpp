#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
    int t,n,big,ans;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d", &n);
        int arr[2][100001]={0};
        int dp[2][100001]={0};
        for(int i=0; i<2; i++) {
            for (int j=1; j<=n; j++)
                scanf(" %d", &arr[i][j]);
        }
        
        dp[0][1]=arr[0][1];
        dp[1][1]=arr[1][1];
        dp[0][2]=dp[1][1]+arr[0][2];
        dp[1][2]=dp[0][1]+arr[1][2];
        
        for(int i=3; i<=n; i++) {
            big=max(dp[0][i-2], dp[1][i-2]);
            dp[0][i]=max(dp[1][i-1]+arr[0][i], big+arr[0][i]);
            dp[1][i]=max(dp[0][i-1]+arr[1][i], big+arr[1][i]);
        }
        ans=max(dp[0][n], dp[1][n]);
        printf("%d\n", ans);
    }
    return 0;
}