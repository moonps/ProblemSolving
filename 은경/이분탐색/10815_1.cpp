#include<cstdio>
#include<algorithm>
int arr1[500002];
int arr2[500002];
using namespace std;
int main(void)
{
    int n,m,first,last,mid;
    
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &arr1[i]);
    
    std::sort(arr1, arr1+n);
    
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &arr2[i]);
    
    for(int i=0; i<m; i++) {
        if(binary_search(arr1,arr1+n,arr2[i])==1) printf("1 ");
        else printf("0 ");
    }
    return 0;
}