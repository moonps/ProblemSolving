#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct data{int x,y;};
queue<data> q;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int arr[102][102],n;
bool safe[102][102];
int ans;
int main(void) {
    int max=0;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
            
            if(arr[i][j]>max)
                max=arr[i][j];
        }
    }

    for(int high=0; high<=max; high++) {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) {
                if(arr[i][j]<=high)
                    safe[i][j]=true;
                else
                    safe[i][j]=false;
            }
        
        int temp=0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j]>high && safe[i][j]==false) {
                    q.push({i,j});
                    safe[i][j]=true;
                    ++temp;
                    
                    while(!q.empty()) {
                        int x=q.front().x;
                        int y=q.front().y;
                        q.pop();
                        
                        for(int k=0; k<4; k++) {
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            
                            if(0<=nx && nx<n && 0<=ny && ny<n) {
                                if(safe[nx][ny]==false) {
                                    safe[nx][ny]=true;
                                    q.push({nx,ny});
                                }
                            }
                        }
                    }
                }
            }
        }

        if(temp>ans)
            ans=temp;
    }
    
    printf("%d", ans);
    return 0;
}