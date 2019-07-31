#include <cstdio>
#include <queue>
struct st {
	int cur;
	int sec;
};
using namespace std;
int N, K;
int ans;
int visit[100005];
int bfs(st start) {
	if (start.cur == K) return 0;
	queue<st> q;
	visit[start.cur] = 1;
	q.push(start);
	while (!q.empty()) {
		st tmp = q.front();
		q.pop();
		if (tmp.cur - 1 == K || tmp.cur + 1 == K || tmp.cur * 2 == K) return tmp.sec + 1; // 동생 찾았니
		if (tmp.cur - 1 >= 0 && tmp.cur - 1 <= 100000 && visit[tmp.cur - 1] == 0) {
			visit[tmp.cur - 1] = 1;
			q.push({ tmp.cur - 1, tmp.sec + 1 });
		}
		if (tmp.cur + 1 >= 0 && tmp.cur + 1 <= 100000 && visit[tmp.cur + 1] == 0) {
			visit[tmp.cur + 1] = 1;
			q.push({ tmp.cur + 1, tmp.sec + 1 });
		}
		if (tmp.cur * 2 >= 0 && tmp.cur * 2 <= 100000 && visit[tmp.cur * 2] == 0) {
			visit[tmp.cur * 2] = 1;
			q.push({ tmp.cur * 2, tmp.sec + 1 });
		}
	}
}
int main(void) {
	scanf("%d %d",&N, &K);
	printf("%d\n", bfs({ N,0 }));
	return 0;
}
