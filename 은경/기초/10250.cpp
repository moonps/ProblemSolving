#include<cstdio>
int arr[100][100];
int main(void)
{
    int t,cnt=0;
    scanf("%d", &t);
    
    while(t--) {
        int h,w,n,cnt=0;
        scanf("%d %d %d", &h, &w, &n);
        
        for(int i=1; i<=w; i++) {
            for(int j=1; j<=h; j++) {
                cnt++;
                if(cnt==n) {
                    printf("%d\n", j*100+i);
                    break;
                }
            }
        }
    }
    
    return 0;
}