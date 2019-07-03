#include<cstdio>
int arr[9];
int main(void) {
    int t; scanf("%d", &t);
    
    while(t--) {
        int n=101, sum=0;
        for(int i=0; i<7; i++) {
            scanf(" %d", &arr[i]);
            if(arr[i]%2==0) {
                sum+=arr[i];
                if(arr[i]<n) n=arr[i];
            }
        }
        printf("%d %d\n", sum,n);
    }
    return 0;
}