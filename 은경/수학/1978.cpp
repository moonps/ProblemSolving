#include<cstdio>
bool arr[1001];
int num[101];
int main(void)
{
    int n,cnt=0;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) scanf("%d", &num[i]);
    
    arr[1]=true;
    for(int i=2; i*i<=1000; i++) {
        if(arr[i]==false)
            for(int j=i*i; j<=1000;j+=i)
                arr[j]=true;
    }
    
    for(int i=1; i<=n; i++) {
        if(arr[num[i]]==false)
            cnt++;
    }
    
    printf("%d", cnt);
    
    return 0;
}