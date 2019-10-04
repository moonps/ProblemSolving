#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
int n, maxVal;
int ans[10];
int arr[10];
bool check[10];
void suyeol(int cnt) {
    if(cnt==n) {
        int temp=0;
        for(int i=0; i<n-1; i++) {
            temp+=abs(ans[i]-ans[i+1]);
        }
        maxVal = maxVal<temp?temp:maxVal;
        return;
    }
    
    for(int i=0; i<n; i++) {
        if(!check[i]) {
            check[i]=true;
            ans[cnt]=arr[i];
            suyeol(cnt+1);
            check[i]=false;
        }
    }
}
int main(void) {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr,arr+n);
    suyeol(0);
    printf("%d",maxVal);
    return 0;
}