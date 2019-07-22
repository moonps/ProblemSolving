#include <cstdio>

using namespace std;
int N;
int V;
int adj[105][105];
int visit[105];
void dfs(int cur) {
	for (int i = 1; i <= N; i++) {
		if (adj[cur][i] == 1 && visit[i] == 0){
			visit[i] = 1;
			dfs(i);
		}
	}
}
int main(void) {
	int ans = 0;
	scanf("%d",&N);
	scanf("%d",&V);
	for (int i = 0; i < V; i++) {
		int from, to;
		scanf("%d %d",&from, &to);
		adj[from][to] = 1;
		adj[to][from] = 1;
	}
	visit[1] = 1;
	dfs(1);
	for (int i = 1; i <= N; i++) {
		ans += visit[i];
	}
	printf("%d\n", ans - 1);
	return 0;
}
