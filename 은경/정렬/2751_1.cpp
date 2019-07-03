#include<cstdio>
int arr[2000001];
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=0,t; i<n; i++){
        scanf("%d", &t);
        arr[t+1000000]++;
    }
    
    for(int i=0;i<=2000000; i++) {
        if (arr[i]==1)
            printf("%d\n", i-1000000);
    }
    return 0;
}