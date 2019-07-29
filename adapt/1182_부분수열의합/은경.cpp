#include<cstdio>
int arr[25];
int n, s, sum, ans=0;
void dfs(int su) {
    if(su>n) return;
    if(sum==s && su==n) {
        ans++;
        return;
    }
    
    sum+=arr[su];
    dfs(su+1);
    
   sum-=arr[su];
    dfs(su+1);
}
int main(void) {
    scanf("%d %d", &n, &s);
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    dfs(0);
    
    if (s==0) ans-=1;
    printf("%d", ans);
    return 0;
}