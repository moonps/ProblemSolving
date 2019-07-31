#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int lvl = 987654321, lvh = 0;
int map[105][105];
int visit[105][105];
int ans, res;
int movex[4] = { 0,0,1,-1 };
int movey[4] = { 1,-1,0,0 };
void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int yto = y + movey[i];
		int xto = x + movex[i];
		if (yto >= 0 && yto < N && xto >= 0 && xto < N && visit[yto][xto] == 0) {
			visit[yto][xto] = 2;
			dfs(yto, xto);
		}
	}
}
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			lvl = min(lvl, map[i][j]);
			lvh = max(lvh, map[i][j]);
		}
	}
	for (int t = lvl - 1; t <= lvh; t++) {
		memset(visit, 0, sizeof(visit));
		res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] <= t) {
					visit[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0) {
					visit[i][j] = 2;
					dfs(i, j);
					res++;
				}
			}
		}
		ans = max(ans, res);
	}
	printf("%d\n",ans);
	return 0;
}
