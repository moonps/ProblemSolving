#include<cstdio>
int main(void)
{
    int n,sum=0,cnt=1;
    scanf("%d", &n);
    
    for(int i=1; i<=n/2+1; i++) {
        for(int j=i; j<=n/2+1; j++) {
            sum+=j;
            if(sum==n) {
                cnt++;
                sum=0;
                break;
            }
            else if (sum>n) {
                sum=0;
                break;
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}