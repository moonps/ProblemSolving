#include<cstdio>
long arr[91];
int main(void)
{
    int n;
    arr[0]=0; arr[1]=1;
    
    for(int i=2; i<=90; i++)
        arr[i]=arr[i-1]+arr[i-2];
    
    scanf("%d", &n);
    
    printf("%ld", arr[n]);
    
    return 0;
}