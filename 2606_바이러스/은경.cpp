#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> arr[102];
bool check[102];
void bfs(int start) {
    queue<int> q;
    check[start]=true; q.push(start);
    
    while(!q.empty()) {
        int node=q.front(); q.pop();
        
        for(int i=0; i<arr[node].size(); i++) {
            int next=arr[node][i];
            
            if(check[next]==false){
                check[next]=true;
                q.push(next);
            }
        }
    }
}
int main(void) {
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    int ans=0,a,b;
    
    for(int i=0; i<k; i++) {
        scanf("%d %d", &a, &b);
        
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    bfs(1);
    
    for(int i=1; i<=n; i++) {
        if(check[i]==true)
            ans++;
    }
    printf("%d", ans-1);
    
    return 0;
}