#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int dis(int py, int px, int y, int x) {
	return (py > y ? py - y : y - py) + (px > x ? px - x : x - px);
}
int main(void) {
	int T;
	scanf("%d",&T);
	for (int t = 0; t < T; t++) {
		int map[22][22];
		int N, M;
		vector<pair<int, int>> home;
		int ans = 1;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) home.push_back(make_pair(i, j));
			}
		}
		if (home.size() == 1) {
			printf("#%d 1\n", t + 1);
			continue;
		}
		bool end = false;
		for (int k = 2; k*k + (k - 1)*(k - 1) <= home.size() * M; k++) {
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					int tmp_ans = 0;
					for (int h = 0; h < home.size(); h++) {
						if (dis(y, x, home[h].first, home[h].second) <= k-1) {
							tmp_ans++;
						}
					}
					if (tmp_ans * M >= k * k + (k - 1)*(k - 1)) {
						ans = max(ans, tmp_ans);
					}
					if (ans == home.size()) {
						end = true;
						break;
					}
				}
				if (end) break;
			}
			if (end) break;
		}
		printf("#%d %d\n", t + 1, ans);
	}
	return 0;
}
