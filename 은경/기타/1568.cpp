#include<cstdio>
int main(void)
{
    int n,cnt=0,j=1;
    scanf("%d", &n);
    
    while(n>0) {
        if(n>=j) {
            n-=j;
            cnt++;
            j++;
        } else {
            j=1;
        }
    }
    printf("%d", cnt);
    
    return 0;
}