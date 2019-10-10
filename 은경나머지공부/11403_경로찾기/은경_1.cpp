#include<cstdio>
#include<cstring>
using namespace std;
int arr[102][102];
int ans[102][102];
bool check[102];
int n;
void dfs(int cur, int node) {
    check[node]=true;
    
    for(int i=1; i<=n; i++) {
        int next=arr[node][i];
        
        if(next!=0 && !check[i]) {
            ans[cur][i]=1;
            dfs(cur, i);
        }
        else if (next!=0 && check[i])
            ans[cur][i]=1;
        else {
            if(ans[node][i]!=0)
                continue;
        }
    }
}
int main(void) {
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i=1; i<=n; i++){
        memset(check,false,sizeof(check));
        dfs(i, i);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}