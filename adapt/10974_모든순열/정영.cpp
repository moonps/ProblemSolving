#include <cstdio>
using namespace std;
int N;
int visit[10];
int ans[10];
void dfs(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			printf("%d ",ans[i] + 1);
		}
		printf("\n");
		return;
	}
	if (cnt > N) return;
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			ans[cnt] = i;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main(void) {
	scanf("%d",&N);
	dfs(0);
	return 0;
}
