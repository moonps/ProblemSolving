#include <cstdio>

using namespace std;
int N, M;
int visit[10];
int ans[10];
void dfs(int cnt) {
	if (cnt > M) return;
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			ans[cnt] = i + 1;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	dfs(0);
	return 0;
}
