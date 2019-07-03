#include<cstdio>
bool arr[1000002];
int main(void)
{
    int n,temp;
    
    for (int i=2; i*i<=1000000; i++) {
        if (arr[i]==false)
            for (int j=i*i; j<=1000000; j+=i)
                arr[j]=true;
    }

    while(scanf("%d", &n)==1) {
        if (n==0) break;
        else {
            for (int j=2; j<=n; j++) {
                if(arr[j]==false) {
                    temp=n-j;
                    if(arr[temp]==false) {
                        printf("%d = %d + %d\n", n,j,temp);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}