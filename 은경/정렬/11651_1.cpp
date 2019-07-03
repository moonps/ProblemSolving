#include<iostream>
#include<utility>
#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> p[100001];
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d %d", &p[i].second, &p[i].first);
    
    sort(p, p+n);
    
    for(int i=0; i<n; i++)
        printf("%d %d\n", p[i].second, p[i].first);
    
    return 0;
}