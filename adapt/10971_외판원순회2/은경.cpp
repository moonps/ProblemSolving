#include<cstdio>
int n, arr[12][12];
bool check[12];
int ans[12];
int minVal=1e9;
void tsp(int cnt,int cur) {
    if(cnt==n) {
        int temp=0,i;
        for(i=0; i<n-1; i++)
            temp+=arr[ans[i]][ans[i+1]];
        if(arr[ans[i]][ans[0]]!=0)
            temp+=arr[ans[i]][ans[0]];
        else
            return;
        minVal=minVal>temp?temp:minVal;
        return;
    }
    
    for(int i=1; i<=n; i++) {
        if(!check[i] && arr[cur][i]!=0) {
            check[i]=true;
            ans[cnt]=i;
            tsp(cnt+1, i);
            check[i]=false;
        }
    }
}
int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &arr[i][j]);
    tsp(0, 1);
    printf("%d", minVal);
    return 0;
}