#include<cstdio>
int arr[102][102];
bool check[102][102];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int n,m,k,r,c,temp,max;
void trash(int x, int y) {
    check[x][y]=true;
    temp++;
    
    for(int k=0; k<4; k++) {
        int nx=x+dx[k];
        int ny=y+dy[k];
        
        if(1<=nx && nx<=n && 1<=ny && ny<=m) {
            if(arr[nx][ny]==1 && !check[nx][ny])
                trash(nx,ny);
        }
    }
}
int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<k; i++){
        scanf("%d %d", &r, &c);
        arr[r][c]=1;
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(arr[i][j]==1 && !check[i][j]){
                temp=0;
                trash(i,j);
                max=max>temp?max:temp;
            }
        }
    }
    
    printf("%d", max);
    return 0;
}