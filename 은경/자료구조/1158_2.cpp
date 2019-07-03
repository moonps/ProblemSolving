#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
    vector<int> v;
    int n,k,cnt=0;
    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++) v.push_back(i);
    
    printf("<");
    while(v.size()!=1) {
        cnt+=k-1;
        cnt%=v.size();
        printf("%d, ",v[cnt]);
        v.erase(v.begin()+cnt);
    }
    printf("%d>", v[0]);
    
    return 0;
}


출처: https://withallmy.tistory.com/106 [삽질 기록용]