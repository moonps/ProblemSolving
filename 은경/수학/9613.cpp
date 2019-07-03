#include<cstdio>
int arr[101];
int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b,a%b);
}
int main(void)
{
    int t,temp;
    long long g;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d", &temp);
        arr[0]={0};
        for(int i=0; i<temp; i++)
            scanf(" %d", &arr[i]);
        g=0;
        for(int i=0; i<temp-1; i++) {
            for(int j=i+1; j<temp; j++)
                g+=gcd(arr[i],arr[j]);
        }
        printf("%lld\n", g);
    }
    return 0;
}