#include<cstdio>
#include<algorithm>
using namespace std;
int check[9]; 
int arr[9]; 
int n,m;
void dfs(int start, int cnt) {
    if(cnt==m) {
        for(int i=1; i<=m; i++){
            printf("%d ", arr[i]);
        }printf("\n");
        return;
    }
    
    for(int i=1; i<=n; i++) {
        if(check[i]==false) {
            check[i]=true;
            arr[cnt+1]=i;
            dfs(start, cnt+1);
            check[i]=false;
        }
    }
}
int main(void) {
    scanf("%d %d", &n, &m);
    
    dfs(1,0);
    
    return 0;
}