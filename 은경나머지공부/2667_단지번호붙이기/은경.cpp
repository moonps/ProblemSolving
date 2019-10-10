#include<cstdio>
#include<algorithm>
using namespace std;
int arr[27][27];
bool check[27][27];
int apt[340];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int n,cnt, temp; // cnt:지금 몇단지인지, temp:단지 안에 아파트가 몇개인지
void danji(int x,int y) {
    check[x][y]=true;
    temp++; //아파트 수 증가
    
    for(int k=0; k<4; k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        
        if(0<=nx && nx<n && 0<=ny && ny<n) {
            if(arr[nx][ny]==1 && !check[nx][ny])
                danji(nx,ny);

        }
    }
}
int main(void) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            scanf("%1d", &arr[i][j]);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {			
            if(arr[i][j]==1 && !check[i][j]) {
                cnt+=1; temp=0; 
                danji(i,j);
                apt[cnt]=temp;
            }
        }
    }
    sort(apt+1, apt+1+cnt);
    printf("%d\n", cnt);
    for(int i=1; i<=cnt; i++)
        printf("%d\n", apt[i]);
    
    return 0;
}