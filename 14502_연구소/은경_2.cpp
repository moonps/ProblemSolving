#include<cstdio>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
int arr[10][10];
int temp_arr[10][10];
int n,m,temp,ans;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
struct d{int x,y;};
queue<struct d> q;
vector<pair<int,int>> v;
void checkVirus(){
    temp=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(temp_arr[i][j]==0)
                temp++;
        }
    }
    ans=temp>ans?temp:ans;
}
void dfs(int x,int y){
    for(int k=0; k<4; k++){
        int nx=x+dx[k], ny=y+dy[k];
        
        if(0<=nx && nx<n && 0<=ny && ny<m){
            if(temp_arr[nx][ny]==0){
                temp_arr[nx][ny]=2;
                dfs(nx,ny);
            }
        }
    }
}
void virus(int cx, int cy, int cnt){
    if(cnt==3){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                temp_arr[i][j]=arr[i][j];
        }
        
        for(int i=0; i<v.size(); i++)
            dfs(v[i].first, v[i].second);

        checkVirus();
        return;
    }
    if(cx>=n)return;
    
    if(cy<m){
        if(arr[cx][cy]==0){
            arr[cx][cy]=1;
            virus(cx,cy+1,cnt+1);
            arr[cx][cy]=0;
            virus(cx,cy+1,cnt);
        } else
            virus(cx, cy+1, cnt);
    } else
        virus(cx+1, 0, cnt);
}

int main(void){
    scanf("%d %d",&n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==2)
                v.push_back(make_pair(i,j));
        }
    }
    
    virus(0,0,0);
    printf("%d",ans);
    return 0;
}