#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct data { int x, y; };
int arr[52][52];
int check[52][52];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int mari[2502];
queue<data> q;
int main(void) {
    int t; scanf("%d", &t);
    
    while(t--){
        memset(arr,0,sizeof(arr));
        memset(check,-1,sizeof(check));
        int num=0;
        
        int m,n,k; scanf("%d %d %d", &m, &n, &k);
        
        for(int i=0; i<k; i++) {
            int x,y; scanf("%d %d", &x, &y);
            arr[x][y]=1; check[x][y]=0;
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]==1 && check[i][j]==0) {
                    check[i][j]=++num;
                    mari[check[i][j]]++;
                    q.push({i,j});
                }
                while(!q.empty()) {
                    int x=q.front().x;
                    int y=q.front().y;
                    
                    for(int k=0; k<4; k++) {
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        
                        if(0<=nx && nx<m && 0<=ny && ny<n) {
                            if(arr[nx][ny]==1 && check[nx][ny]==0) {
                                check[nx][ny]=check[i][j];
                                mari[check[i][j]]++;
                                q.push({nx,ny});
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
        printf("%d\n", num);
    }
    
    return 0;
}