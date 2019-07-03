#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int main(void)
{
    queue<int> q;
    char order[6];
    int t,n;
    scanf("%d", &t);
    
    while(t--) {
        order[0]='\0';
        scanf("%s", order);
        if(order[0]=='p') {
            if(order[1]=='u') {
                scanf("%d", &n);
                q.push(n);
            }
            else if(order[1]=='o') {
                if(!q.empty()) {
                    printf("%d\n", q.front());
                    q.pop();
                } else
                    printf("-1\n");
            }
        } else if (order[0]=='f') {
            if(q.empty()) printf("-1\n");
            else printf("%d\n", q.front());
        } else if (order[0]=='e') {
            if(q.empty()) printf("1\n");
            else printf("0\n");
        } else if (order[0]=='s')
            printf("%d\n", q.size());
        else if (order[0]=='b') {
            if(q.empty()) printf("-1\n");
            else printf("%d\n", q.back());
        }
    }

    return 0;
}