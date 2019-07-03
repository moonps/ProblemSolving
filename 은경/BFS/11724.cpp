#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
bool check[1001];
vector<int> arr[1001];
int cnt=0;
void bfs(int start) {
    queue<int> q;
    check[start]=true; q.push(start);
    
    while(!q.empty()) {
        int node=q.front(); q.pop();
        
        for(int i=0; i<arr[node].size(); i++) {
            int next=arr[node][i];
            if(check[next]==false) {
                check[next]=true;
                q.push(next);
            }
        }
    }
    cnt+=1;
}
int main(void)
{
    int n,m,u,v;
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++) {
        scanf("%d %d", &u, &v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++) {
        if(check[i]==false)
            bfs(i);
        
    }
    printf("%d\n",cnt);
    
    return 0;
}