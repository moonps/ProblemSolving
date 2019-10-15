#include<cstdio>
using namespace std;
bool visited[100002];
int v[100002];
int n,m,p,ans,a,b;
void dfs(int hate){
    if(!visited[hate]){
        visited[hate]=true;
        if(v[hate]!=0){
            ans++;
            dfs(v[hate]);
        }
    }
    else
        ans=-1;
}
int main(void){
    scanf("%d %d %d", &n, &m, &p);
    
    for(int i=1; i<=n; i++){
        scanf("%d %d", &a, &b);
        if(v[b]==0)
            v[b]=a;
    }
    dfs(p);
    
    printf("%d",ans);
    
    return 0;
}
