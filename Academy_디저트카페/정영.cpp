#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int map[22][22];
int ans;
int movex[4] = { 1,-1,-1,1 };
int movey[4] = { 1,1,-1,-1 };
int same[105];
int sy, sx;
void dfs(int y, int x, int dir, int cnt) {
	if (dir == 3 && y == sy && x == sx) {
		ans = max(ans, cnt);
	}
	// 방향 안바꿈
	int yto = y + movey[dir];
	int xto = x + movex[dir];
	if (yto >= 0 && yto < N && xto >= 0 && xto < N) {
		if (same[map[yto][xto]] == 0) {
			same[map[yto][xto]] = 1;
			dfs(yto, xto, dir, cnt + 1);
			same[map[yto][xto]] = 0;
		}
	}
	// 방향 바꿈
	if (dir < 3) {
		yto = y + movey[dir + 1];
		xto = x + movex[dir + 1];
		if (yto >= 0 && yto < N && xto >= 0 && xto < N) {
			if (same[map[yto][xto]] == 0) {
				same[map[yto][xto]] = 1;
				dfs(yto, xto, dir + 1,cnt + 1);
				same[map[yto][xto]] = 0;
			}
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		ans = 0;
		scanf("%d",&N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				memset(same, 0, sizeof(same));
				sy = i;
				sx = j;
				dfs(i, j, 0, 0);
			}
		}

		printf("#%d %d\n", t + 1, ans == 0 ? -1 : ans);
	}
	return 0;
}
