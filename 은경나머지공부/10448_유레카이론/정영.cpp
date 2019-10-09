#include <stdio.h>
int N;
int num;
int ans;
int visit[500];
int gauss(int n) {
	return n * (n + 1) / 2;
}
void dfs(int step, int cnt, int sum) {
	if (sum > num) return;
	if (cnt == 3) {
		if (sum == num) {
			ans = 1;
		}
		return;
	}
	if (gauss(step) < num) {
		if (visit[step] < 3) {
			visit[step]++;
			dfs(step, cnt + 1, sum + gauss(step));
			visit[step]--;
		}
		dfs(step + 1, cnt, sum);
	}
}
int main(void) {
	scanf("%d", &N);
	while (N--) {
		ans = 0;
		scanf("%d", &num);
		dfs(1, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
