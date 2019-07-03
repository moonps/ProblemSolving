#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int arr[11];
int main(void)
{
    int n,ans=0;
    scanf("%d", &n);
    
    if(n==0) {
        printf("1");
        exit(0);
    }
    while(n>0) {
        arr[n%10]++;
        n/=10;
    }
    int temp=arr[6]+arr[9];
    if(temp%2==0) arr[6]=temp/2;
    else arr[6]=temp/2+1;
    
    for(int i=0; i<9; i++)
        ans=max(ans,arr[i]);
    printf("%d", ans);
    
    return 0;
}