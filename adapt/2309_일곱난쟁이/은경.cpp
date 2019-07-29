#include<cstdio>
#include<algorithm>
#include<cstdio>
using namespace std;
int arr[10], sum, stop;
bool check[10];
void dfs(int nan, int cnt) {
    if(stop==0) {
        if(cnt==7 && sum==100) {
            stop=1;
            for(int i=0; i<9; i++)
                if(check[i])
                    printf("%d\n", arr[i]);
            return;
        }
        
        if(cnt>7 || sum>100 || nan>=9) return;
        
        check[nan]=true;
        sum+=arr[nan];
        dfs(nan+1, cnt+1);
        
        sum-=arr[nan];
        check[nan]=false;
        dfs(nan+1, cnt);
    }
}
int main(void) {
    for(int i=0; i<9; i++)
        scanf("%d", &arr[i]);
    
    sort(arr,arr+9);
    dfs(0,0);
    
    return 0;
}