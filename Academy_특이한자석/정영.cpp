#include <cstdio>
#include <cstring>
using namespace std;
int top[5][10];
void move(int target, int dir) {
	int tmp[8];
	for (int i = 0; i < 8; i++) {
		tmp[i] = top[target][i];
	}
	if (dir == 1) {
		for (int i = 0; i < 7; i++) {
			top[target][i + 1] = tmp[i];
		}
		top[target][0] = tmp[7];
	}
	else if (dir == -1){
		for (int i = 0; i < 7; i++) {
			top[target][i] = tmp[i + 1];
		}
		top[target][7] = tmp[0];
	}
}
int point(void) {
	int p = 1;
	int sum = 0;
	for (int i = 1; i < 5; i++) {
		sum += top[i][0] * p;
		p *= 2;
	}
	return sum;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int K;
		scanf("%d",&K);
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &top[i][j]);
			}
		}
		for (int k = 0; k < K; k++) {
			int tt, dd;
			scanf("%d %d", &tt, &dd);
			int is_move[5] = { 0, };
			is_move[tt] = dd;
			for (int i = tt; i <= 3; i++) {
				if (top[i][2] != top[i + 1][6]) {
					is_move[i + 1] = is_move[i] * -1;					
				}
				else break;
			}
			for (int i = tt; i >= 2; i--) {
				if (top[i - 1][2] != top[i][6]) {
					is_move[i - 1] = is_move[i] * -1;
				}
				else break;
			}
			for (int i = 1; i <= 4; i++) {
				if (is_move[i] != 0) move(i, is_move[i]);
			}
		}
		printf("#%d %d\n", t + 1, point());
	}
	return 0;
}
