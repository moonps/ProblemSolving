#include<cstdio>
bool arr[1001];
int num[101];
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=2; i*i<=n; i++) {
        while (n%i==0) {
            printf("%d\n", i);
            n/=i;
        }
    }
    
    if(n>1)
        printf("%d\n", n);
    
    return 0;
}