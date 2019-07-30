#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct data{int x,y;};
queue<data> q;
vector<data> v;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int arr[51][51], check[51][51];
int n,m,ans=102, temp, flag, cnt;
void check_time(){
    temp=0, flag=0, cnt;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(check[i][j]==-1) {
                flag=1;
                break;
            }
            if (temp!=-1 && check[i][j]>=temp)
                temp=check[i][j];
        }
    }
}
void bfs() {
    // 일단 원본 복사
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 벽이면 -2로 해놓고
            if(arr[i][j]==1)
                check[i][j]=-2;
            // 아닌 곳들은 -1 (0인 빈칸이나 바이러스가 이동할 수 있는 2인 곳들)
            else
                check[i][j]=-1;
        }
    }
    
    // 고른 m개의 위치에 바이러스 놓기
    for(int i=0; i<v.size(); i++) {
        int x = v[i].x;
        int y = v[i].y;
        check[x][y]=0;
        q.push({x,y});
    }
    
    // 바이러스 퍼트리기
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int k=0; k<4; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            
            if(0<=nx && nx<n && 0<=ny && ny<n) {
                // 바이러스가 퍼지지 않았거나
                // 바이러스가 퍼지긴 했는데 더 짧은 시간에 퍼질 수 있다면
                if(check[nx][ny]==-1 || check[nx][ny]>check[nx][ny]+1) {
                    check[nx][ny]=check[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    // 퍼진 시간 체크
    check_time();
}
void dfs(int cx, int cy, int cnt) {
    if(cnt==m) {
        bfs();
        if (flag==1 && ans==102) ans=102;
        else if(flag==0 && ans>temp)
            ans=temp;
        //printf("%d ", ans);
        return ;
    }
    
    if(cx>=n) return ;
    
    if(cy<n) {
        if(arr[cx][cy]==2) {
            v.push_back({cx,cy});
            dfs(cx, cy+1, cnt+1);
            v.pop_back();
            dfs(cx, cy+1, cnt);
        } else {
            dfs(cx,cy+1,cnt);
        }
    } else {
        dfs(cx+1,0,cnt);
    }
}
int main(void) {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
    
    dfs(0,0,0);
    if(ans==102)
        printf("-1");
    else
        printf("%d", ans);
    return 0;
}