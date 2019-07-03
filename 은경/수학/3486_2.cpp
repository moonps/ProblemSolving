#include<cstdio>
int main(void)
{
    int n,a,b,temp1,temp2,temp3,result;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &a, &b);
        temp1=0; temp2=0; temp3=0; result=0;

        while(a>=10) {
            temp1=temp1*10+a%10;
            a/=10;
        } temp1=temp1*10+a;
        
        while(b>=10) {
            temp2=temp2*10+b%10;
            b/=10;
        } temp2=temp2*10+b;
        
        temp3=temp1+temp2;
        
        while(temp3>=10) {
            result=result*10+temp3%10;
            temp3/=10;
        } result=result*10+temp3;
        
        printf("%d\n", result);
    }
    
    return 0;
}