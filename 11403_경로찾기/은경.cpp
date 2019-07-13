#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[102];
//queue<int> q;
int arr[102][102];
bool check[102][102];
int n;
void bfs(int start) {
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        int node=q.front(); q.pop();
        
        for(int i=1; i<=n; i++) {
            if (arr[node][i]==1 && check[start][i]==false) {
                check[start][i]=true;
                q.push(i);
            }
        }
    }
}

int main(void) {
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=1; i<=n; i++)
        bfs(i);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            printf("%d ", check[i][j]);
        printf("\n");
    }
    
    return 0;
}