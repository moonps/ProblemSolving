#include<iostream>
#include<cstdio>
int main(void)
{
    int dp[12]={0,1,2,4,};
    int t,n;
    scanf("%d", &t);
    
    for (int j=4; j<=10; j++)
        dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
    
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}