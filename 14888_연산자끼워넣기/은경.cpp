#include<cstdio>
#include<algorithm>
using namespace std;
int arr[13];
int op[5];
int n,maxVal=-1000000000,minVal=1000000000;
void dfs(int plus, int sub, int mul, int div, int cnt, int sum){
    if (cnt==n) {
        maxVal=max(maxVal,sum);
        minVal=min(minVal,sum);
    }
    
    if(plus>0) dfs(plus-1, sub, mul, div, cnt+1, sum+arr[cnt]);
    if (sub>0) dfs(plus, sub-1, mul, div, cnt+1, sum-arr[cnt]);
    if (mul>0) dfs(plus, sub, mul-1, div, cnt+1, sum*arr[cnt]);
    if (div>0) dfs(plus, sub, mul, div-1, cnt+1, sum/arr[cnt]);
}
int main(void) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<4; i++) scanf("%d", &op[i]);
    
    dfs(op[0],op[1],op[2],op[3],1,arr[0]);
    printf("%d %d", maxVal, minVal);
    return 0;
}