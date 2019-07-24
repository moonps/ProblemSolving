#include <cstdio>
#include <cstring>

using namespace std;
int X, Y, K;
int map[55][55];
int visit[55][55];
int movex[4] = { 0,0,-1,1 };
int movey[4] = { -1,1,0,0 };
int ans;
void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int yto = y + movey[i];
		int xto = x + movex[i];
		if (yto >= 0 && yto < Y && xto >= 0 && xto < X && map[yto][xto] == 1 && visit[yto][xto] == 0) {
			visit[yto][xto] = 1;
			dfs(yto, xto);
		}
	}
}
int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		ans = 0;
		scanf("%d %d %d", &X, &Y, &K);
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					visit[i][j] = 1;
					dfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
