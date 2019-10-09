#include<cstdio>
int arr[22];
bool check[22];
int sum, n, s, answer;
void bubun(int cnt, int cur, int res) {
    if(cnt==res) {
        if(sum==s)
            answer++;
        return;
    }
    
    for(int i=cur; i<n; i++){
        check[i]=true;
        sum+=arr[i];
        bubun(cnt+1, i+1, res);
        check[i]=false;
        sum-=arr[i];
    }
}
int main(void) {
    scanf("%d %d", &n, &s);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    for(int i=1; i<=n; i++)
            bubun(0,0,i);
    
    printf("%d", answer);
    return 0;
}