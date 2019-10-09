#include<cstdio>
#include<cstring>
using namespace std;
int arr[52][52];
bool check[52][52];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int ans,t,m,n,k,x,y;
void jirung(int x, int y) {
    // 인근 배추들 전부 지렁이 보내줘야함
    check[x][y]=1;
    
    for(int k=0; k<4; k++) {
        int nx=x+dx[k];
        int ny=y+dy[k];
        
        if(0<=nx && nx<m && 0<=ny && ny<n) {
            if(arr[nx][ny]==1 && check[nx][ny]==0)
                jirung(nx,ny);
        }
    }
}
int main(void) {
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        memset(arr,0,sizeof(arr)); ans=0;
        memset(check,0,sizeof(check));
        scanf("%d %d %d", &m, &n, &k);
        
        for(int j=0; j<k; j++) {
            scanf("%d %d", &x, &y);
            arr[x][y]=1;
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                // 배추가 있고 지렁이가 없으면 (아직 방문 X) 지렁이를 놓아주자
                if(arr[i][j]==1 && check[i][j]==0) {
                    ans++;
                    jirung(i,j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}