#include <cstdio>

using namespace std;
int S[55];
int visit[55];
int k;
void dfs(int step, int cnt){
	if (cnt == 6) {
		for (int i = 0; i < k; i++) {
			if (visit[i] == 1) printf("%d ", S[i]);
		}
		printf("\n");
		return;
	}
	if (step >= k) return;

	visit[step] = 1;
	dfs(step + 1, cnt + 1);
	visit[step] = 0;
	dfs(step + 1, cnt);
}
int main(void) {
	while (true) {
		scanf("%d", &k);
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			scanf("%d", &S[i]);
		}
		dfs(0, 0);
		printf("\n");
	}
	return 0;
}
