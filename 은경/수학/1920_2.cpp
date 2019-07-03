#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100001];
int check[100001];
bool BinarySearch(int *arr, int len, int key) {
    int start=0;
    int end=len-1;
    int mid;
    
    while(end-start>=0) {
        mid = (start+end)/2;
        
        if(arr[mid]==key) return true;
        else if (arr[mid]>key) end=mid-1;
        else start=mid+1;
    }
    return false;
}
int main(void)
{
    int n,m;

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    sort(arr, arr+n);
    
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &check[i]);
    
    for(int i=0; i<m; i++) {
        if(BinarySearch(arr,n,check[i])) printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}
