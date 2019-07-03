#include<cstdio>
#include<algorithm>
int arr1[500002];
int arr2[500002];
int binary_s(int *ar, int len, int target) {
    int first=0;
    int last=len-1;
    int mid=0;
    
    while(first<=last) {
        mid=(first+last)/2;
        if(ar[mid]==target) return 1;
        else {
            if(ar[mid]>target) last=mid-1;
            else first=mid+1;
        }
    }
    return 0;
}
int main(void)
{
    int n,m;
    
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &arr1[i]);
    
    std::sort(arr1, arr1+n);
    
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &arr2[i]);
    
    for(int i=0; i<m; i++)
        printf("%d ", binary_s(arr1,n,arr2[i]));
    
    return 0;
}