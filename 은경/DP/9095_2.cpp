#include<iostream>
#include<cstdio>
int arr[10002];
int dp[12];
int main(void)
{
    int t;
    scanf("%d", &t);
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    for (int i=1; i<=t; i++) {
        scanf("%d", &arr[i]);
        for (int j=4; j<=arr[i]; j++)
            dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
        printf("%d\n", dp[arr[i]]);
    }
    return 0;
}
