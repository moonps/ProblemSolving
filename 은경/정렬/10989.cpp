#include<cstdio>
int arr[10002];
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=0,t; i<n; i++){
        scanf("%d", &t);
        arr[t]++;
    }
    
    for(int i=1;i<=10000; i++) {
        if (arr[i]!=0) {
            for(int j=0; j<arr[i]; j++)
                printf("%d\n", i);
        }
    }
    return 0;
}