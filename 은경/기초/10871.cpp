#include<cstdio>
int arr[10002];
int main(void)
{
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    for (int i=0; i<n; i++)
        if(arr[i]<x)
            printf("%d ", arr[i]);
    
    return 0;
}