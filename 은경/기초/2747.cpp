#include<cstdio>
int arr[46];
int main(void)
{
    int n;
    arr[0]=0; arr[1]=1;
    
    for(int i=2; i<=45; i++)
        arr[i]=arr[i-1]+arr[i-2];
    
    scanf("%d", &n);
    
    printf("%d", arr[n]);
    
    return 0;
}