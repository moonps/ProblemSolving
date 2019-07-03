#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int arr[1001][1001];
bool check[1001]; //dfs
int n,m,v;
void dfs(int node) {
    check[node]=true;
    printf("%d ", node);
    
    for(int i=1; i<=n; i++) {
        if(arr[node][i]==1 && check[i]==false)
            dfs(i);
    }
}
void bfs(int start) {
    queue<int> q;
    memset(check,false,sizeof(check));
    
    check[start]=true; q.push(start);
    while(!q.empty()) {
        int node=q.front(); q.pop();
        printf("%d ", node);
        
        for(int i=1; i<=n; i++) {
            if(arr[node][i]==1 && check[i]==false) {
                check[i]=true;
                q.push(i);
            }
        }
    }
}
int main(void)
{
    int a,b;
    scanf("%d %d %d", &n, &m, &v);
    
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a,&b);
        arr[a][b]=arr[b][a]=1;
    }
    
    dfs(v);
    printf("\n");
    bfs(v);
    
    return 0;
}