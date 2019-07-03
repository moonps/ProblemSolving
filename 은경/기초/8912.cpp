#include<cstdio>
#include<cstring>
int arr[1001];
int main(void)
{
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n,cnt,sum=0;
        memset(arr,0,sizeof(arr));
 
        scanf("%d", &n);
        
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        for(int i=1; i<n; i++) {
            cnt=0;
            for(int j=0; j<i; j++) {
                if(arr[i]>=arr[j])
                    cnt++;
            }
            sum+=cnt;
        }
        printf("%d\n", sum);
    }
    return 0;
}