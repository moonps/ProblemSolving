#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
vector<int> arr[1002];
queue<int> q;
bool check[1002];
int n,m,u,v,ans;
void dfs(int node) {
    check[node]=true;
    
    for(int i=0; i<arr[node].size(); i++) {
        int next=arr[node][i];
        if(!check[next])
            dfs(next);
    }
}
void bfs(int start) {
    check[start]=true; q.push(start);
    
    while(!q.empty()) {
        int node=q.front(); q.pop();
        
        for(int i=0; i<arr[node].size(); i++){
            int next=arr[node][i];
            
            if(!check[next]) {
                q.push(next);
                check[next]=true;
            }
        }
    }
}
int main(void) {
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &u, &v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++) {
        if(!check[i]) {
//            dfs(i);
            bfs(i);
            ans++;
        }
    }
    printf("%d", ans);
    
    return 0;
}