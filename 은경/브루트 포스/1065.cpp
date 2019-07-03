#include<cstdio>
int main(void)
{
    int x,i,cnt=0,temp,r;
    int arr[4];
    scanf("%d", &x);
    
    if (x<100) printf("%d", x);
    else {
        for (int j=100; j<=x; j++) {
            temp=j;
            if (temp==1000) break;
            for (i=1; temp>0; i++) {
                arr[i]=temp%10;
                temp/=10;
            }
            if (arr[3]-arr[2] == arr[2]-arr[1])
                cnt++;
        }
        r=99+cnt;
        printf("%d", r);
    }
    return 0;
}