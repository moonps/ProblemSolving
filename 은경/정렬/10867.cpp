#include<cstdio>
int arr[2002];
int main(void)
{
    int n,t;
    scanf("%d", &n);
    
    for (int i=0; i<n; i++){
        scanf("%d", &t);
        arr[t+1000]++;
    }
    
    for (int i=0; i<2001; i++)
        if(arr[i]>0)
            printf("%d ", i-1000);
    
    return 0;
}