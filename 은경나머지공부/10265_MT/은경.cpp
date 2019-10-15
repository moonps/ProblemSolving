#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1002];
bool check[1002];
bool finished[1002];
int pp[1002];
vector<int> v;
int n,k,temp,cnt;
void bus(int n){
    check[n]=true;
    int next=arr[n];
    
    // 사이클 발생
    if(check[next]){
        if(!finished[next]){
            temp=0;
            for(int i=next; i!=n; i=arr[i])
                temp++;
            temp++;
            pp[n]=temp;
            
            for(int i=next; i!=n; i=arr[i]){
                pp[i]=temp;
            }
        }
    }
    else
        bus(next);
    finished[n]=true;
    if(pp[n]==0)
        pp[n]=1+pp[next];
}
int main(void){
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    if(n<=k)
        printf("%d", n);
    else {
        for(int i=1; i<=n; i++){
            if(!check[i])
                bus(i);
        }
        sort(pp+1,pp+n+1);
        
        for(int i=n; i>=1; i--){
            if(pp[i]<=k) {
                printf("%d",pp[i]);
                break;
            }
        }
    }
    return 0;
}
