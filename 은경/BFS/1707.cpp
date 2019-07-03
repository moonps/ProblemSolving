#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int> arr[20001];
queue<int> q;
int check[20001];
bool bfs(int start) {
    check[start]=1; q.push(start);
    
    while(!q.empty()) {
        int node=q.front(); q.pop();
        
        for(int i=0; i<arr[node].size(); i++) {
            int next=arr[node][i];
            
            if(check[next]==0) {
                check[next]=(3-check[node]);
                q.push(next);
            } else if (check[next]==check[node])
                return false;
        }
    }
    return true;
}
int main(void)
{
    int t,v,e,a,b;
    scanf("%d", &t);
    
    while(t--) {
        bool ans=true;

        scanf("%d %d", &v, &e);
        for(int i=0; i<e; i++) {
            scanf("%d %d", &a, &b);
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        
        for(int i=1; i<=v; i++) {
            if(check[i]==0) {
                if(bfs(i)==false) {
                    printf("NO\n");
                    ans=false;
                    break;
                }
            }
        }
        
        if(ans) printf("YES\n");
        
        while(!q.empty()) q.pop();
        for(int i=0; i<=v; i++) arr[i].clear();
        memset(check,0,sizeof(check));
    }
    return 0;
}