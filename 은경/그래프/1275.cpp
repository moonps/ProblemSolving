#include<cstdio>
int arr[100001];
void swap(int *x, int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main(void)
{
    int n,q,x,y,a,b;
    scanf("%d %d", &n, &q);
    
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    for(int i=0; i<q; i++) {
        long long sum=0;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if(x>y) swap(&x, &y);
        for(int i=x; i<=y; i++) sum+=arr[i];
        arr[a]=b;
        
        printf("%lld\n", sum);
    }
    return 0;
}