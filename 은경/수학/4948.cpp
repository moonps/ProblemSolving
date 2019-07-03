#include<cstdio>
bool arr[246914];
int main(void)
{
    int n,cnt;
    
    arr[1]=true;
    
    for (int i = 2; i*i <= 246912; i++)
        if (arr[i] == false)
            for (int j = i * i; j <= 246912; j += i)
                arr[j] = true;
    
    while(scanf("%d", &n)==1) {
        if (n==0) break;
        else {
            cnt=0;
            for (int i=n+1; i<=2*n; i++)
                if(arr[i]==false)
                    cnt++;
            printf("%d\n", cnt);
        }
    }
    return 0;
}