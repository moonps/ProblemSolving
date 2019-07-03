#include<iostream>
#include<utility>
#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> p[100001];
bool cmp(const pair<int, int> &u, const pair<int, int> &v) {
    if(u.second ==v.second) return u.first<v.first;
    else return u.second<v.second;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d %d", &p[i].first, &p[i].second);
    
    sort(p,p+n,cmp);
    
    for(int i=0; i<n; i++)
        printf("%d %d\n", p[i].first, p[i].second);
    
    return 0;
}