#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int map[105][105];
int movex[4] = { 0,0,1,-1 };
int movey[4] = { 1,-1,0,0 };
vector<int> ans;
int Y, X, K;
int piv = 2;
void search() {
	for (int i = 0; i < piv - 2; i++) {
		ans.push_back(0);
	}
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] >= 2) {
				ans[map[y][x] - 2]++;
			}
		}
	}
}
void dfs(int yy, int xx, int piv) {
	for (int i = 0; i < 4; i++) {
		int yto = yy + movey[i];
		int xto = xx + movex[i];
		if (yto >= 0 && yto < Y && xto >= 0 && xto < X && map[yto][xto] == 0) {
			map[yto][xto] = piv;
			dfs(yto, xto, piv);
		}
	}
}
int main(void) {
	scanf("%d %d %d", &Y, &X, &K);
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				map[y][x] = 1;
			}
		}
	}
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] == 0) {
				map[y][x] = piv;
				dfs(y, x, piv);
				piv++;
			}
		}
	}
	search();
	sort(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
