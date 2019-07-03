#include<cstdio>
bool arr[10001];
int D(int x)
{
    if(x<10) return x+x;
    else {
        int temp,sum=0;
        temp=x;
        while(temp>0) {
            sum+=(temp%10);
            temp/=10;
        }
        return x+sum;
    }
}
int main(void)
{
    for(int i=1; i<=10000; i++)
        arr[D(i)]=true;

    for(int i=1; i<=10000; i++) {
        if(arr[i]==false)
            printf("%d\n", i);
    }
    return 0;
}