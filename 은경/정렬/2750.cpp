#include<cstdio>
int arr[1001];
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    for(int i=2,j; i<=n; i++) {
        int key=arr[i];
        for(j=i-1; j>=1 && arr[j]>key; j--)
            arr[j+1]=arr[j];
        arr[j+1]=key;
    }
    
    for(int i=1; i<=n; i++)
        printf("%d\n", arr[i]);
            
    return 0;
}