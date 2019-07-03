#include<cstdio>
int main(void)
{
    int n,i=1,temp=0;
    scanf("%d", &n);
    
    while(temp<=n) {
        temp=(3*i*i)-(3*i)+2;
        if(temp>n)
            break;
        else
            i++;
    }
    printf("%d", i);
    
    return 0;
}