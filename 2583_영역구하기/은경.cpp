#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct data{int x,y;};
queue<data> q;
int m,n,k,arr[102][102], cnt=0, size[102];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i=0; i<k; i++) {
        int x1,x2,y1,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        for(int cx=x1; cx<x2; cx++)
            for(int cy=y1; cy<y2; cy++)
                arr[cx][cy]=-1;
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]==0) {
                q.push({i,j});
                arr[i][j]=++cnt;

                while(!q.empty()) {
                    int x=q.front().x;
                    int y=q.front().y;
                    q.pop();
                    
                    for(int t=0; t<4; t++) {
                        int nx=x+dx[t];
                        int ny=y+dy[t];

                        if(0<=nx && nx<m && 0<=ny && ny<n) {
                            if(arr[nx][ny]==0) {
                                arr[nx][ny]=cnt;
                                q.push({nx,ny});
                                size[cnt]++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n", cnt);
    sort(size+1, size+1+cnt);
    for(int i=1; i<=cnt; i++)
        printf("%d ", size[i]+1);
    return 0;
}