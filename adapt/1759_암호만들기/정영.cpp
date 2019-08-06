#include <cstdio>
#include <algorithm>
using namespace std;
int L, C;
int visit[17];
char candi[17];
bool check() {
	int ja = 0;
	int mo = 0;
	for (int i = 0; i < C; i++) {
		if (visit[i] == 1) {
			if (candi[i] == 'a' ||
				candi[i] == 'e' ||
				candi[i] == 'i' ||
				candi[i] == 'o' ||
				candi[i] == 'u') mo++;
			else ja++;
		}
	}
	if (mo >= 1 && ja >= 2) return true;
	return false;
}
void dfs(int step, int cnt) {
	if (cnt == L) {
		if (check()) {
			for (int i = 0; i < C; i++) {
				if (visit[i] == 1) {
					printf("%c", candi[i]);
				}
			}
			printf("\n");
		}
		return;
	}
	if (step >= C) return;

	visit[step] = 1;
	dfs(step + 1, cnt + 1);
	visit[step] = 0;
	dfs(step + 1, cnt);
}
int main(void) {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &candi[i]);
	}
	sort(&candi[0], &candi[C]);
	dfs(0, 0);
	return 0;
}
