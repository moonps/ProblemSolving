#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
deque<int> dq;
char str[12];
int main(void)
{
    int t,n;
    scanf("%d", &t);
    
    while(t--) {
        str[0]='\0';
        scanf("%s", str);
        
        if(str[0]=='p') {
            if(str[1]=='u') {
                if(str[5]=='f') {
                    scanf("%d", &n);
                    dq.push_front(n);
                } else {
                    scanf("%d", &n);
                    dq.push_back(n);
                }
            } else {
                if(str[4]=='f') {
                    if(!dq.empty()) {
                        printf("%d\n", dq.front());
                        dq.pop_front();
                    } else printf("-1\n");
                } else {
                    if(!dq.empty()) {
                        printf("%d\n", dq.back());
                        dq.pop_back();
                    } else printf("-1\n");
                }
            }
        } else if (str[0]=='s') { printf("%d\n", dq.size());
        } else if (str[0]=='e') { if(!dq.empty()) printf("0\n"); else printf("1\n");
        } else if (str[0]=='f') {
            if(!dq.empty())
                printf("%d\n", dq.front());
            else
                printf("-1\n");
        } else if (str[0]=='b') {
            if(!dq.empty())
                printf("%d\n", dq.back());
            else
                printf("-1\n");
        }
    }
    return 0;
}