#include<cstdio>
int main(void)
{
    int n,temp=0,i=1;
    scanf("%d", &n);
    
    while(temp<=n) {
        temp=1+(i*(i-1)/2);
        if(temp>n)
            break;
        else
            i++;
    }
    temp=1+(i-1)*(i-2)/2;
    int order=n-temp;
    int before=i-1-order;
    int after=1+order;
    
    if(i%2==0)
        printf("%d/%d",before,after);
    else
        printf("%d/%d", after,before);
 
    return 0;
}