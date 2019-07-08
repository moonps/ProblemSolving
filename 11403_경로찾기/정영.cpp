#include<cstdio>
#include<cstring>

using namespace std;
int N;
int ad[105][105];
int path[105][105];
int visit[105];

void dfs(int cur, int step){
	if (step > 0) visit[cur] = 1;
	for (int i = 0; i < N; i++) {
		if (ad[cur][i] == 1 && visit[i] == 0) {
			dfs(i, step+1);
		}
	}
}
int main(void){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d",&ad[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i, 0);
		for (int k = 0; k < N; k++) {
			path[i][k] = visit[k];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
	return 0;
}
