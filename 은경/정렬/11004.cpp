#include<cstdio>
#include<vector>
#include<algorithm>
int ar[5000001];
using namespace std;
int main(void)
{
    int n,k;
    scanf("%d %d", &n, &k);
    
    for (int i=0; i<n; i++)
        scanf("%d", &ar[i]);
    
    nth_element(ar,ar+k-1,ar+n);
    printf("%d", ar[k-1]);
    
    return 0;
}
