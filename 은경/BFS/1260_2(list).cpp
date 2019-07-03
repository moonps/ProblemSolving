#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
vector<int> arr[1001];
bool check[1001];
void dfs(int node) {
    check[node]=true;
    printf("%d ", node);
    
    for(int i=0; i<arr[node].size(); i++) {
        int next=arr[node][i];
        if(check[next]==false)
            dfs(next);
    }
}
void bfs(int start) {
    queue<int> q;
    memset(check,false,sizeof(check));
    
    check[start]=true; q.push(start);
    while(!q.empty()) {
        int node=q.front(); q.pop();
        printf("%d ", node);
        
        for(int i=0; i<arr[node].size(); i++) {
            int next=arr[node][i];
            if(check[next]==false) {
                check[next]=true;
                q.push(next);
            }
        }
    }
}
int main(void)
{
    int n,m,v,a,b;
    scanf("%d %d %d", &n, &m, &v);
    queue<int>q;
    
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a,&b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++)
        sort(arr[i].begin(), arr[i].end());
    
    dfs(v);
    printf("\n");
    bfs(v);

    return 0;
}