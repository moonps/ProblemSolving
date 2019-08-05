#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int visit[10];
int order[10];
int arr[10];
int ans;
int calc() {
	int res = 0;
	for (int i = 0; i < N - 1; i++) {
		int tmp = order[i] - order[i + 1];
		if (tmp < 0) tmp = tmp * -1;
		res += tmp;
	}
	return res;
}
void dfs(int cnt) {
	if (cnt == N) {
		ans = max(ans, calc());
		return;
	}
	if (cnt > N) return;
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			order[cnt] = arr[i];
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
