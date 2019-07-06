#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int h,w;
char map[105][105];
int visit[105][105];
int keys[30];
int ans;
vector<pair<int,int>> ent;
int movex[4] = {0,0,1,-1};
int movey[4] = {1,-1,0,0};
vector<pair<int,int>> cannotopen[30];
int check(char c){ //doc : -1 , space : 0, key : 1  , door : 2  , else : 3
    if (c == '$') return -1;
    else if (c == '.' || c == 0) return 0; //테두리도 탐색 가능 하도록 0 도 같이 넣어줌.
    else if (c >= 'a' && c <= 'z') return 1;
    else if (c >= 'A' && c <= 'Z') return 2;
    else return 3;
}

void bfs(pair<int,int> start){
    queue<pair<int,int>> q;
    
    if (map[start.first][start.second] == '$') ans++;
    
    visit[start.first][start.second] = 1;
    q.push(start);
    
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int yto = tmp.first + movey[i];
            int xto = tmp.second + movex[i];
            if (xto >= 0 && xto <= w + 1 && yto >= 0 && yto <= h + 1 && visit[yto][xto] == 0){
                int ch = check(map[yto][xto]);
                if (ch == -1){
                    ans++;
                    visit[yto][xto] = 1;
                    q.push(make_pair(yto,xto));
                }
                else if (ch == 0){
                    visit[yto][xto] = 1;
                    q.push(make_pair(yto,xto));
                }
                else if (ch == 1){
                    keys[map[yto][xto]-'a']++;
                    visit[yto][xto] = 1;
                    q.push(make_pair(yto,xto));
                    
                    if (keys[map[yto][xto]-'a'] == 1){ // 처음 발견된 키이면 못열었던 문들 다시 탐색 하도록 큐에 추가
                        for (int k = 0; k < cannotopen[map[yto][xto]-'a'].size(); k++){
                            visit[cannotopen[map[yto][xto]-'a'][k].first][cannotopen[map[yto][xto]-'a'][k].second] = 1;
                            q.push(make_pair(cannotopen[map[yto][xto]-'a'][k].first, cannotopen[map[yto][xto]-'a'][k].second));
                        }
                        cannotopen[map[yto][xto]-'a'].clear(); //이후 탐색 하지 않도록 clear
                    }
                }
                else if (ch == 2){
                    if (keys[map[yto][xto]-'A'] == 0){ //문인데 키가 없어서 못열면, 리스트에 추가 해둠
                        cannotopen[map[yto][xto]-'A'].push_back(make_pair(yto,xto));
                    }
                    else{
                        visit[yto][xto] = 1;
                        q.push(make_pair(yto,xto));
                    }
                }
            }
        }
    }
    
}

int main(void){
    
    int T;
    scanf("%d", &T);
    
    while(T--){
        memset(keys,0,sizeof(keys));
        memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));
        ent.clear();
        for(int i = 0; i<30; i++){
            cannotopen[i].clear();
        }
        ans = 0;
        
        scanf("%d %d", &h, &w);
        for (int i = 1; i<=h; i++){ //빌딩 밖으로 나갈수 있어서 테두리 남겨둠.
            for (int j = 1; j <= w; j++){
                scanf(" %1c", &map[i][j]);
            }
        }
        
        char key_string[30];
        scanf("%s", key_string);
        for (int i = 0; i<strlen(key_string); i++){
            if (key_string[i] == '0') break;
            keys[key_string[i]-'a']++;
        }
        
        bfs(make_pair(0,0));
        printf("%d\n",ans);
    }
    
    return 0;
}
