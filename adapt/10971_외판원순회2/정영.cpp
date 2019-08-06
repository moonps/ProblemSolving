#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int visit[12];
int adj[12][12];
int ans = 987654321;
int start;
void dfs(int node, int sum, int cnt) {
	if (sum >= ans) return; // 더이상 탐색할 필요 없음
	if (node == start && cnt == N) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (adj[node][i] != 0 && visit[i] == 0) {
			visit[i] = 1;
			dfs(i, sum + adj[node][i], cnt + 1);
			visit[i] = 0;
		}
	}
}
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		start = i;
		dfs(i, 0, 0);
	}
	printf("%d\n", ans);
	return 0;
}
