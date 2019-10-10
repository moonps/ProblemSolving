#include<cstdio>
#include<cstring>
using namespace std;
int arr[102][102];
bool check[102][102];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int n,t1,t2,t3,ans1,ans2;
// 적록색약 아닌 사람이 봤을 때 (빨,초,파 구분)
void func1(int x, int y, int cur){
    check[x][y]=true;
    
    for(int k=0; k<4; k++) {
        int nx=x+dx[k], ny=y+dy[k];
        
        if(0<=nx && nx<n && 0<=ny && ny<n) {
            if(arr[nx][ny]==cur && !check[nx][ny])
                func1(nx,ny,cur);
        }
    }
}
//적록색약이 봤을 때 (빨-초, 파 구분)
void func2(int x, int y, int cur){
    check[x][y]=true;
    
    for(int k=0; k<4; k++) {
        int nx=x+dx[k], ny=y+dy[k];
        
        if(0<=nx && nx<n && 0<=ny && ny<n) {
            if((arr[nx][ny]==cur || arr[nx][ny]==3-cur)&& !check[nx][ny]){
                        func2(nx,ny,cur);
            }
        }
    }
}
int main(void) {
    scanf("%d\n", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char temp; scanf("%c", &temp);
            if(temp=='R') arr[i][j]=1;
            else if (temp=='G') arr[i][j]=2;
            else if (temp=='B') arr[i][j]=3;
        }
        char temp; scanf("%c", &temp);
    }
    
    // 색약 아님
    for(int k=1; k<=3; k++) {
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(arr[i][j]==k && !check[i][j]) {
                    ans1++;
                    func1(i,j,k);
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            check[i][j]=false;
    }
    
    // 색약임
    for(int k=1; k<=3; k++) {
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(arr[i][j]==k && !check[i][j]) {
                    ans2++;
                    func2(i,j,k);
                }
            }
        }
    }
    
    
    printf("%d %d", ans1, ans2);
    
    return 0;
}