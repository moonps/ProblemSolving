#include <stdio.h>
int main(void) {
	int N;
	int len = 1;
	int ans = 0;
	scanf("%d", &N);
	int cnt = 10;
	while (true) {
		if (N / cnt == 0) {
			break;
		}
		len++;
		cnt *= 10;
	}
	for (int i = N - 9 * len; i < N; i++) {
		int sum = 0;
		int num = i;
		for (int k = 0; k < len; k++) {
			sum += num % 10;
			num /= 10;
		}
		if (sum + i == N) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
