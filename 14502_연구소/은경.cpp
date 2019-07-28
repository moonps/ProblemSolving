#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct data{int x,y;};
int arr[10][10]; // 원본
int virus[10][10]; //바이러스 퍼질시
int n,m,ans=0;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
queue<data> q;
void check_virus() {
    int temp=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(virus[i][j]==0)
                temp++;
        }
    }

    if(temp>ans)
        ans=temp;
}
void bfs() {
    while(!q.empty()) {
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        
        for(int k=0; k<4; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            
            if(0<=nx && nx<n && 0<=ny && ny<m) {
                if(virus[nx][ny]==0) {
                    virus[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
        }
    }
    check_virus();
    
}
void dfs(int cx, int cy, int cnt) {
    if(cnt == 3) {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) {
                virus[i][j]=arr[i][j];
                if(arr[i][j]==2)
                    q.push({i,j});
            }
        
        bfs();
        return ;
    }
    
    else if (cx>=n) return;
    
    if (cy<m) {
        if(arr[cx][cy]==0) {
            arr[cx][cy]=1;
            dfs(cx, cy+1, cnt+1);
            arr[cx][cy]=0;
            dfs(cx, cy+1, cnt);
        } else
            dfs(cx, cy+1, cnt);
    } else
        dfs(cx+1, 0, cnt);
}
int main(void) {
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &arr[i][j]);
            
            if (arr[i][j]==2)
                q.push({i,j});
        }
    }
    
    dfs(0,0,0);

    printf("%d", ans);
    
    return 0;
    
}