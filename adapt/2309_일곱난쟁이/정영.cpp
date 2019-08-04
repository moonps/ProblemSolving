#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int visit[9];
bool if_found = false;
void dfs(int step, int cnt) {
	if (if_found) return;
	if (cnt == 7) {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			if (visit[i] == 1) {
				sum += vec[i];
			}
		}
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (visit[i] == 1) {
					printf("%d\n", vec[i]);
				}
			}
			if_found = true;
		}
		return;
	}
	if (step >= 9) return;

	visit[step] = 1;
	dfs(step + 1, cnt + 1);
	visit[step] = 0;
	dfs(step + 1, cnt);
}
int main(void) {
	for (int i = 0; i < 9; i++) {
		int tmp;
		scanf("%d",&tmp);
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	dfs(0, 0);
	return 0;
}
