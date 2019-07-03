#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100001];
long long money[100001];
int main(void)
{
    int n,m;
    long long ans;
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for(int i=0; i<m; i++)
        money[0]+=arr[i];
    
    for(int i=1; i<=(n-m); i++) {
        money[i]=money[i-1]-arr[i-1]+arr[i+m-1];
    }
    
    sort(money, money+(n-m+1));
    printf("%lld", money[n-m]);
    
    return 0;
}