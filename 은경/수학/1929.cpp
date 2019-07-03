#include<cstdio>
bool arr[1000002];
int main(void)
{
    int n,m;
    scanf("%d %d", &m, &n);
    arr[1]=true;
    
    for (int i = 2; i*i <= 1000000; i++)
        if (arr[i] == false)
            for (int j = i * i; j <= 1000000; j += i)
                arr[j] = true;
            
    for (int i=m; i<=n; i++)
        if(arr[i]==false)
            printf("%d\n", i);
    return 0;
}