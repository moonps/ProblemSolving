#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int arr[52][52];
int visited[52][52];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int n,m,r,c,l,ans,cnt,temp;
struct d{int cx; int cy;};
queue<d> q;
void bfs(){
    while(!q.empty()){
        int x=q.front().cx;
        int y=q.front().cy;
        q.pop();
        
        if(visited[x][y]==l){
            ans=temp;
            break;
        }
        
        for(int k=0; k<4; k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(k==0 && arr[x][y]!=2 && arr[x][y]!=6 && arr[x][y]!=7){
                    if(arr[nx][ny]==1 || arr[nx][ny]==3 || arr[nx][ny]==6 || arr[nx][ny]==7){
                        if(!visited[nx][ny]){
                            q.push({nx,ny});
                            visited[nx][ny]=visited[x][y]+1;
                            temp++;
                        }
                    }
                } else if(k==1 && arr[x][y]!=2 && arr[x][y]!=4 && arr[x][y]!=5){
                    if(arr[nx][ny]==1 || arr[nx][ny]==3 || arr[nx][ny]==4 || arr[nx][ny]==5){
                        if(!visited[nx][ny]){
                            q.push({nx,ny});
                            visited[nx][ny]=visited[x][y]+1;
                            temp++;
                        }
                    }
                } else if(k==2 && arr[x][y]!=3 && arr[x][y]!=4 && arr[x][y]!=7){
                    if(arr[nx][ny]==1 || arr[nx][ny]==2 || arr[nx][ny]==4 || arr[nx][ny]==7){
                        if(!visited[nx][ny]){
                            q.push({nx,ny});
                            visited[nx][ny]=visited[x][y]+1;
                            temp++;
                        }
                    }
                } else if(k==3 && arr[x][y]!=3 && arr[x][y]!=5 && arr[x][y]!=6) {
                    if(arr[nx][ny]==1 || arr[nx][ny]==2 || arr[nx][ny]==5 || arr[nx][ny]==6){
                        if(!visited[nx][ny]){
                            q.push({nx,ny});
                            visited[nx][ny]=visited[x][y]+1;
                            temp++;
                        }
                    }
                }
            }
        }
    }
}
int main(void){
    int T; scanf("%d", &T);
    
    for(int tc=0; tc<T; tc++){
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
        q.push({r,c});
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                scanf("%d", &arr[i][j]);
        }
        
        memset(visited,0,sizeof(visited));
        ans=0; temp=1;
        visited[r][c]=1;
        bfs();
        
        if(ans!=0) printf("#%d %d\n", tc+1, ans);
        else printf("#%d %d\n", tc+1, temp);
        
        while(!q.empty()){
            q.pop();
        }
    }
    return 0;
}