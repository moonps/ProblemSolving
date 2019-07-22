#include <cstdio>
#include <algorithm>

using namespace std;
int N;
int op[15]; // 0:+, 1:- 2:x 3:/
int number[15];
int visit[15]; // op사용기록
int op_order[15];
int ans_min = 987654321;
int ans_max = -987654321;
int calc() {
	int res = number[0];
	for (int i = 0; i < N - 1; i++) {
		if (op_order[i] == 0) { // 더하기
			res = res + number[i + 1];
		}
		else if (op_order[i] == 1){ // 빼기
			res = res - number[i + 1];
		}
		else if (op_order[i] == 2) { // 곱하기
			res = res * number[i + 1];
		}
		else if (op_order[i] == 3) { // 나누기
			res = res / number[i + 1];
		}
	}
	return res;
}
void dfs(int step) {
	if (step == N - 1) {
		int res = calc();
		ans_min = min(ans_min, res);
		ans_max = max(ans_max, res);
	}
	if (step > N - 1) return;
	for (int i = 0; i < N - 1; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			op_order[step] = op[i];
			dfs(step + 1);
			visit[i] = 0;
		}
	}
}
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int tmp;
		scanf("%d", &tmp);
		for (int k = 0; k < tmp; k++) {
			op[cnt++] = i; // 연산자들 한개씩 배열에 저장
		}
	}
	dfs(0);
	printf("%d\n%d\n",ans_max,ans_min);
	return 0;
}
