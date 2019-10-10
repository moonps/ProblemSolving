#include<cstdio>
#include<algorithm>
using namespace std;
int arr[102][102];
bool check[102][102];
int ans[1002];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int m,n,k,x1,y1,x2,y2,cnt,temp;
void place(int x, int y) {
    check[x][y]=true;
    temp++;
    
    for(int k=0; k<4; k++) {
        int nx=x+dx[k];
        int ny=y+dy[k];
        
        if(0<=nx && nx<m && 0<=ny && ny<n) {
            if(arr[nx][ny]==0 && !check[nx][ny])
                place(nx,ny);
        }
    }
}
int main(void) {
    scanf("%d %d %d", &m, &n, &k);
    
    for(int i=0; i<k; i++) {
        scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
        
        for(int y=y1; y<y2; y++){
            for(int x=x1; x<x2; x++)
                arr[y][x]=1;
        }
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]==0 && !check[i][j]){
                cnt+=1; temp=0;
                place(i,j);
                ans[cnt]=temp;
            }
        }
    }
    
    sort(ans+1, ans+1+cnt);
    printf("%d\n", cnt);
    for(int i=1; i<=cnt; i++)
        printf("%d ", ans[i]);
    return 0;
}