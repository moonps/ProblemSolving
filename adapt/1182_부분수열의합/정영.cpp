#include <cstdio>
using namespace std;
int N, S;
int map[22];
int visit[22];
int ans;
void dfs(int step, int sum, bool enable) { //enable : sum == S 검사를 해도 가능한 경우를 분별 하기 위함                                
	if (enable && sum == S) ans++;
	if (step >= N) return;
	visit[step] = 1;
	dfs(step + 1, sum + map[step], true);
	visit[step] = 0;
	dfs(step + 1, sum, false); //선택한 원소 갯수는 증가하지 않고 step만 증가하는 경우에는 검사를 하면 안됨.
}
int main(void){
	scanf("%d %d",&N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d",&map[i]);
	}
	dfs(0, 0, false);
	printf("%d\n",ans);
	return 0;
}
