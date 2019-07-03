#include<cstdio>
int arr[11];
int main(void)
{
    int n,sum=0,temp;
    scanf("%d", &n);
    
    while(1) {
        temp=n;
        sum=0;
        for(int i=0; temp>=1; i++) {
            arr[i]=(temp%10);
            temp/=10;
            sum+=arr[i];
        }
        if(n%sum==0) {
            printf("%d", n);
            break;
        }
        else
            n++;
    }
    
    return 0;
}