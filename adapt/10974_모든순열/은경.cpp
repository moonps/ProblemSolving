#include<cstdio>
int n;
int arr[10];
bool check[10];
void suyeol(int cnt) {
    if(cnt==n) {
        for(int i=0; i<n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    
    for(int i=1; i<=n; i++) {
        if(!check[i]) {
            check[i]=true;
            arr[cnt]=i;
            suyeol(cnt+1);
            check[i]=false;
        }
    }
}
int main(void) {
    scanf("%d", &n);
    suyeol(0);
    return 0;
}