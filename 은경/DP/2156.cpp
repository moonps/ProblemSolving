#include<cstdio>
#include<algorithm>
#include<iostream>
int arr[10002];
int dp[10002];
using namespace std;
int main(void)
{
    int n,ans;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) scanf(" %d", &arr[i]);
    
    dp[1]=arr[1];
    dp[2]=arr[1]+arr[2];
    
    for(int i=3; i<=n; i++)
        dp[i]=max({dp[i-1],dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]});
    
    ans=max(dp[n],dp[n-1]);
    printf("%d", ans);
    return 0;
}