#include<cstdio>
#include<cstring>
using namespace std;
int arr[102][102];
bool check[102][102];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,k,high,temp,ans;
void count(int x, int y, int rain){
    check[x][y]=true;
    
    for(int k=0; k<4; k++) {
        int nx=x+dx[k];
        int ny=y+dy[k];
        
        if(0<=nx && nx<n && 0<=ny && ny<n){
            if(arr[nx][ny]>rain && !check[nx][ny])
                count(nx,ny,rain);
        }
    }
}
void safe(int rain){
    memset(check,false,sizeof(check));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(arr[i][j]>rain && !check[i][j]){
                temp++;
                count(i,j,rain);
            }
        }
    }
}
int main(void) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
            high=high>arr[i][j]?high:arr[i][j];
        }
    }
    for(int i=0; i<=high; i++) {
        temp=0;
        safe(i);
        ans=temp>ans?temp:ans;
    }
    
    printf("%d", ans);
    return 0;
}