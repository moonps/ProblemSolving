#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct DATA {int x,y;};
queue<DATA> q;
queue<DATA> door[28];
int dx[]={0,0,1,-1,}, dy[]={1,-1,0,0};
bool check[102][102];
char arr[102][102];
bool key[102];
char keys[102];
int main(void) {
    int t; scanf("%d", &t);
    
    while(t--) {
        int h,w,ans=0;
        scanf("%d %d", &h, &w);
        
        // 입력을 받습니다
        for(int i=1; i<=h; i++) {
            for(int j=1; j<=w; j++) {
                scanf(" %c", &arr[i][j]);
            }
        }
        
        // 가지고 있는 열쇠 체크!
        scanf("%s", keys);
        for(int i=0; i<strlen(keys); i++) {
            if (keys[i]=='0') continue;
            key[keys[i]-'a']=true;
        }
        
        // 테두리를 만든다
        for(int j=0; j<=w+1; j++) {
            arr[0][j]='.';
            arr[h+1][j]='.';
        }
        for(int i=1; i<=h; i++) {
            arr[i][0]='.';
            arr[i][w+1]='.';
        }
        
        q.push({0,0}); check[0][0]=true;
        while(!q.empty()) {
            int x=q.front().x;
            int y=q.front().y;
            q.pop();
            
            for(int k=0; k<4; k++) {
                int nx=x+dx[k];
                int ny=y+dy[k];
                
                if (0<=nx && nx<=h+1 && 0<=ny && ny<=w+1) {
                    // 벽이거나 이미 방문했었던 공간이면 무시
                    if(arr[nx][ny]=='*' || check[nx][ny]) {
                        continue;
                    }
                    
                    // 어차피 아래 모든 곳에 방문하게 되니까 방문처리 먼저 해줌
                    check[nx][ny]=true;
                    
                    // 문서이면 줍줍하고 큐에 넣기
                    if (arr[nx][ny]=='$'){
                        ans++;
                        q.push({nx,ny});
                    }
                    
                    // 이동할 수 있는 빈 공간이면 큐에 넣기
                    else if (arr[nx][ny]=='.') {
                        q.push({nx,ny});
                    }
                    
                    // 열쇠면 줍고 큐에 넣고 0으로 만들고 열쇠 가졌따고 표시
                    else if ('a'<=arr[nx][ny] && arr[nx][ny]<='z') {
                        q.push({nx,ny});
                        
                        // 주운 열쇠가 없었던 열쇠면 줍는다
                        if(key[arr[nx][ny]-'a']==false) {
                            key[arr[nx][ny]-'a']=true;
                        
                            // 그리고 해당 열쇠랑 맞는 문을 다 열어준다
                            while(!door[arr[nx][ny]-'a'].empty()) {
                                q.push({door[arr[nx][ny]-'a'].front()});
                                door[arr[nx][ny]-'a'].pop();
                            }
                        }
                    }
                    
                    // 문이면 가지고 있는 열쇠랑 일치하는지 확인
                    else if ('A'<=arr[nx][ny] && arr[nx][ny]<='Z') {
                        // 해당 알파벳에 맞는 키가 존재하면
                        if(key[arr[nx][ny]-'A']==true) {
                            q.push({nx,ny}); // 문 위치를 큐에 넣기
                        }
                        // 열쇠랑 일치하지 않으면 문 큐에 넣기
                        else {
                            door[arr[nx][ny]-'A'].push({nx,ny});
                        }
                    }
                }
            }
        }
        
        printf("%d\n", ans);
        
        memset(check,0,sizeof(check));
        memset(arr,0,sizeof(arr));
        memset(key,false,sizeof(key));
        memset(keys,false,sizeof(keys));
        for(int i=0; i<28; i++) {
            while(!door[i].empty())
                door[i].pop();
        }
    }
    return 0;
}
