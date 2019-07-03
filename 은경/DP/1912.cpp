#include<cstdio>
#include<algorithm>
#include<iostream>
int arr[100002];
using namespace std;
int main(void)
{
    int n,mmax=-1001;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        arr[i]=max(arr[i], arr[i]+arr[i-1]);
        mmax=max(mmax,arr[i]);
    }
    printf("%d", mmax);
    return 0;
}