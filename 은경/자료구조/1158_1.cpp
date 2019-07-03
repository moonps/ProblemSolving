#include<cstdio>
#include<queue>
using namespace std;
int main(void)
{
    queue<int> q;
    int n,k,t,cnt=1;
    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++) q.push(i);
    
    printf("<");
    while(q.size()!=1) {
        if(cnt%k == 0) {
            printf("%d, ", q.front());
            q.pop();
            cnt++;
        }   else {
            t=q.front();
            q.pop();
            q.push(t);
            cnt++;
        }
    }
    printf("%d>",q.front());
    
    return 0;
}


출처: https://withallmy.tistory.com/106 [삽질 기록용]