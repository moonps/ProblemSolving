#include<cstdio>
int dp[101];
int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b,a%b);
}
int main(void)
{
    int a,b,g,l;
    scanf("%d %d", &a, &b);
    
    g=gcd(a,b);
    l=a*b/g;
    printf("%d\n%d", g,l);
    
    return 0;
}