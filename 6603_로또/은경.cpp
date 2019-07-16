#include<cstdio>
#include<cstring>
int arr[15];
int check[15];
int k;
void dfs(int start, int cnt) {
    if (cnt==6) {
        for(int i=0; i<6; i++) {
            printf("%d ", check[i]);
        }
        printf("\n");
    }
    for(int i=start; i<k; i++) {
        check[cnt] = arr[i];
        dfs(i+1, cnt+1);
    }
}
int main(void)
{
    while(scanf("%d", &k) == 1) {
        int cnt=0;
        memset(arr,0,sizeof(arr));
        memset(check,0,sizeof(check));

        if(k==0)
            break;
        
        for(int i=0; i<k; i++)
            scanf(" %d", &arr[i]);
        
        dfs(0,0);
        printf("\n");
    }
    return 0;
}