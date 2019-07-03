#include<cstdio>
#include<algorithm>
int a[301],dp[301];
using namespace std;
int main(void)
{
    int x;
    scanf("%d", &x);

    for (int i=1; i<=x; i++) scanf("%d", &a[i]);
    
    dp[0]=0;
    dp[1]=a[1];
    dp[2]=a[1]+a[2];
    
    for (int i=3; i<=x; i++)
        dp[i]=max(dp[i-2]+a[i], dp[i-3]+a[i-1]+a[i]);
    
    printf("%d", dp[x]);
    return 0;
}
