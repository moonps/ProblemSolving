#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
vector<int> arr[1001];
queue<int> q;
bool check[1001];
void bfs(int start) {
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
}
int main(void)
{
    int t,n,a,cnt;
    scanf("%d", &t);
    
    while(t--) {
        cnt=0;
        scanf("%d", &n);
        
        for(int i=1; i<=n; i++) {
            scanf("%d", &a);
            arr[i].push_back(a);
        }
        
        for(int i=1; i<=n; i++) {
            if(check[i]==false) {
                bfs(i);
                cnt++;
            }
        }
        printf("%d\n", cnt);
        memset(check,false,sizeof(check));
        while(!q.empty()) q.pop();
        for(int i=0; i<=n; i++) arr[i].clear();
    }
    
    return 0;
}