#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
char arr[104][104];
int visit[104][104], dx[] = { 0,0,1,-1 }, dy[] = { 1, -1, 0, 0 };
struct DATA {
    int x, y, d;
}D;
int main()
{
    int i, j, a, b, ans;
    scanf("%d %d", &a, &b);
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= b; j++)
        {
            scanf(" %c", &arr[i][j]);
        }
    }
    queue<DATA> q;
    visit[1][1] = 1;
    D.x = 1;
    D.y = 1;
    D.d = 1;
    q.push(D);
    while (!q.empty())
    {
        int x1, y1, d1;
        x1 = q.front().x;
        y1 = q.front().y;
        d1 = q.front().d;
        q.pop();
        if (x1 == a && y1 == b)
        {
            ans = d1;
            break;
        }
        for (i = 0; i < 4; i++)
        {
            D.x = x1 + dx[i];
            D.y = y1 + dy[i];
            D.d = d1 + 1;
            if (D.x > 0 && D.x <= a && D.y > 0 && D.y <= b)
            {
                if (arr[D.x][D.y] == '1' && visit[D.x][D.y] == 0)
                {
                    visit[D.x][D.y] = 1;
                    q.push(D);
                }
            }
        }
    }
    printf("%d", ans);
    
    return 0;
}
