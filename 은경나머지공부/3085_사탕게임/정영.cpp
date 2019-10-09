#include <cstdio>
int N;
char map[55][55];
int ans = 0;
int return_max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	//sero loop
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N - 1; k++) {
			int len = 1;
			int can_change = true;
			char pivot = map[i][k];
			while (true) {
				ans = return_max(ans, len);
				if (k + len >= N) break;
				if (map[i][k + len] == pivot) {
					len++;
				}
				else {
					if (len == 1) {
						if (k > 0) {
							if (map[i][k - 1] == map[i][k + len]) {
								len++;
								pivot = map[i][k - 1];
								can_change = false;
								continue;
							}
						}
						if (i - 1 >= 0) {
							if (map[i - 1][k] == map[i][k + len]) {
								len++;
								pivot = map[i - 1][k];
								can_change = false;
								continue;
							}
						}
						if (i + 1 < N) {
							if (map[i + 1][k] == map[i][k + len]) {
								len++;
								pivot = map[i + 1][k];
								can_change = false;
								continue;
							}
						}
					}
					if (can_change) {
						if (i - 1 >= 0) {
							if (map[i - 1][k + len] == pivot) {
								can_change = false;
								len++;
								continue;
							}
						}
						if (i + 1 < N) {
							if (map[i + 1][k + len] == pivot) {
								can_change = false;
								len++;
								continue;
							}
						}
						if (k + len + 1 < N) {
							if (map[i][k + len + 1] == pivot) {
								can_change = false;
								len++;
								ans = return_max(ans, len);
								break;
							}
						}
						break;
					}
					else {
						break;
					}
				}
			}
		}
	}

	//garo loop
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N - 1; k++) {
			int len = 1;
			int can_change = true;
			char pivot = map[k][i];
			while (true) {
				ans = return_max(ans, len);
				if (k + len >= N) break;
				if (map[k + len][i] == pivot) {
					len++;
				}
				else {
					if (len == 1) {
						if (k > 0) {
							if (map[k - 1][i] == map[k + len][i]) {
								len++;
								pivot = map[k - 1][i];
								can_change = false;
								continue;
							}
						}
						if (i - 1 >= 0) {
							if (map[k][i - 1] == map[k + len][i]) {
								len++;
								pivot = map[k][i - 1];
								can_change = false;
								continue;
							}
						}
						if (i + 1 < N) {
							if (map[k][i + 1] == map[k + len][i]) {
								len++;
								pivot = map[k][i + 1];
								can_change = false;
								continue;
							}
						}
					}
					if (can_change) {
						if (i - 1 >= 0) {
							if (map[k + len][i - 1] == pivot) {
								can_change = false;
								len++;
								continue;
							}
						}
						if (i + 1 < N) {
							if (map[k + len][i + 1] == pivot) {
								can_change = false;
								len++;
								continue;
							}
						}
						if (k + len + 1 < N) {
							if (map[k + len + 1][i] == pivot) {
								can_change = false;
								len++;
								ans = return_max(ans, len);
								break;
							}
						}
						break;
					}
					else {
						break;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
