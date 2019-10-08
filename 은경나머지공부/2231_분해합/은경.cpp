#include<cstdio>
int main(void) {
    int n,i; scanf("%d", &n);
    for(i=1; i<=n; i++) {
        int sum=i; int temp=i;
        while(temp>0) {
            sum+=(temp%10);
            temp/=10;
        }
        if(n==sum){
            printf("%d", i);
            break;
        }
    }
    if (i>n)
        printf("0");
    return 0;
}