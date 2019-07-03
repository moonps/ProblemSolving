#include<cstdio>
#include<algorithm>
int arr[10002];
using namespace std;
int main(void)
{
    int n,ans,a1,a2,a3,a4;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr,arr+n);
    
    a1=arr[n-1]*arr[n-2];
    a2=arr[0]*arr[1];
    a3=arr[n-1]*arr[n-2]*arr[n-3];
    a4=arr[0]*arr[1]*arr[n-1];
    ans=max({a1,a2,a3,a4});
    printf("%d", ans);
    return 0;
}