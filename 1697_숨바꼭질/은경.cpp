#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q;
bool check[100002];
int n,k,ans=0;
void jump(int node) {
    if(0<=node && node<=100000 && !check[node]) {
        if(check[node]==false) {
            check[node]=true;
            q.push(node);
        }
    }
}
void bfs(int start) {
    q.push(start); check[start]=true;
    
    while(!check[k]) {
        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            int node=q.front(); q.pop();
            
            jump(node-1);
            jump(node+1);
            jump(node*2);
        }
        ans++;
    }
}
int main(void) {
    scanf("%d %d", &n, &k);
    
    bfs(n);
    
    printf("%d", ans);
    return 0;
}
