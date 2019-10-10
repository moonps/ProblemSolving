#include<cstdio>
#include<cstring>
using namespace std;
int arr[100002]; //같이 탑승하고 싶은 사람
bool visited[100002]; // 방문했니
bool finished[100002]; // 끝났니
int cnt;
void dfs(int node) {
    visited[node]=true;
    int next=arr[node];
    
    // 방문 예정인 다음 정점을 이미 방문을 했었니
    if(visited[next]){
        // 했었는데 아직 방문함수가 다 안 끝났다면
        // 싸이클 발생 조건 성립 : dfs(4) -> dfs(7) -> dfs(6) 일때 visited[4]=true && finished[4]=false
        if(!finished[next]) {
            // 마지막 방문한 정점에서 싸이클에 속하는 정점 모두 찾아내기
            // 싸이클을 만드니까 자기자신 만날때까지 돌면 된다
            for(int i=next; i!=node; i=arr[i])
                cnt++;
            cnt++; // 자기자신
        }
    }
    // 방문조차 안했으면 dfs 실행
    else
        dfs(next);
    finished[node]=true;
}
int main(void) {
    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n; scanf("%d", &n);
        for(int j=1; j<=n; j++) scanf("%d", &arr[j]);
        
        cnt=0;
        memset(visited,false,sizeof(visited));
        memset(finished,false,sizeof(finished));
        for(int j=1; j<=n; j++){
            if(!visited[j])
                dfs(j);
        }
        // 전체 정점 개수 - 사이클에 속한 정점 개수
        printf("%d\n", n-cnt);
    }
    return 0;
}
