#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100001];
int check[100001];
int main(void)
{
    int n,m;

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    sort(arr, arr+n);
    
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &check[i]);
    
    for(int i=0; i<m; i++) {
        if(binary_search(arr,arr+n,check[i])) printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}