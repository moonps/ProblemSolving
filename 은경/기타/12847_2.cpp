#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100001];
long long money[100001];
int main(void)
{
    int n,m;
    long long ans=0,temp=0;
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i<m) temp+=arr[i];
    }
    
    ans=temp;
    for(int i=m; i<n; i++) {
        temp+=arr[i]-arr[i-m];
        ans=max(temp,ans);
    }
    
    printf("%lld", ans);
    
    return 0;
}