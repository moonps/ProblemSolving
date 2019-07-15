#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int map[10][10];
int tmp_map[10][10];
int Y, X;
int ans = 0;
vector<pair<int, int>> virus;
int movex[4] = { 0,0,1,-1 };
int movey[4] = { 1,-1,0,0 };

int safe_area() {
	int sum = 0;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (tmp_map[i][j] == 0) sum++;
		}
	}
	return sum;
}

void dfs2(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int yto = y + movey[i];
		int xto = x + movex[i];
		if (yto >= 0 && yto < Y && xto >= 0 && xto < X && tmp_map[yto][xto] == 0) {
			tmp_map[yto][xto] = 2;
			dfs2(yto, xto);
		}
	}
}
void dfs(int y, int x, int cnt) {
	if (cnt == 3) { //기둥 3개 세웠으면..
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				tmp_map[i][j] = map[i][j];
			}
		}
		//바이러스 퍼뜨리기
		for (int i = 0; i < virus.size(); i++) {
			dfs2(virus[i].first, virus[i].second);
		}
		//안전영역 최대값 갱신
		ans = max(ans, safe_area());
		return;
	}

	if (y >= Y) return; // 끝까지 다 돌았을때.

	//2차원 맵 순차 탐색 시작
	if (x < X) { //X방향으로 한칸씩 이동
		if (map[y][x] == 0) { //빈칸일때만 기둥 세워보도록.
			map[y][x] = 1;
			dfs(y, x + 1, cnt + 1);
			map[y][x] = 0;
			dfs(y, x + 1, cnt);
		}
		else { //빈칸이 아니면 다음칸 탐색
			dfs(y, x + 1, cnt);
		}
	}
	else dfs(y + 1, 0, cnt); //다음줄 탐색
	
}
int main(void) {
	scanf("%d %d", &Y, &X);
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 2) {
				virus.push_back(make_pair(y, x));
			}
		}
	}
	dfs(0, 0, 0);
	printf("%d\n", ans);
	return 0;
}
