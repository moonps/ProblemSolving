#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
int map[55][55];
int cp_map[55][55];
int N, M;
vector<pair<int, int>> virus_candi;
int visit[12]; // dfs용
int movex[4] = { 0,0,1,-1 };
int movey[4] = { 1,-1,0,0 };
int ans = 987654321;
struct vi {
	pair<int, int> loc;
	int sec;
};
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cp_map[i][j] == 0 || cp_map[i][j] == 2) return true; //바이러스가 못퍼진곳이 있으면
		}
	}
	return false;
}
int bfs(vector<pair<int, int>> st) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cp_map[i][j] = map[i][j];
		}
	}
	int cur_sec;
	queue<vi> q;
	for (int i = 0; i < M; i++) {
		cp_map[st[i].first][st[i].second] = 3;
		q.push({st[i],0});
	}
	while (!q.empty()) {
		vi tmp = q.front();
		q.pop();
		cur_sec = tmp.sec;
		for (int i = 0; i < 4; i++) {
			int yto = tmp.loc.first + movey[i];
			int xto = tmp.loc.second + movex[i];
			if (yto >= 0 && yto < N && xto >= 0 && xto < N && cp_map[yto][xto] != 3 && cp_map[yto][xto] != 1) {
				cp_map[yto][xto] = 3;
				q.push({ make_pair(yto,xto),tmp.sec + 1 });
			}
		}
	}
	if (check()) return -1;
	return cur_sec;
}
void dfs(int step, int cnt) {
	if (cnt == M) {
		vector<pair<int, int>> start;
		for (int i = 0; i < virus_candi.size(); i++) {
			if (visit[i] == 1) {
				start.push_back(virus_candi[i]);
			}
		}
		int tmp_ans = bfs(start);
		if (tmp_ans != -1) ans = min(ans, tmp_ans);
		return;
	}
	if (step >= virus_candi.size()) return;
	
	visit[step] = 1;
	dfs(step + 1, cnt + 1);
	visit[step] = 0;
	dfs(step + 1, cnt);
}
int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d",&map[i][j]);
			if (map[i][j] == 2) virus_candi.push_back(make_pair(i, j));
		}
	}
	dfs(0,0);
	printf("%d\n", ans == 987654321 ? -1 : ans);
	return 0;
}
