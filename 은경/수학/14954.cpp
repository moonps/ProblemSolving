#include<cstdio>
int ff(int n) {
    int ans=0;
    while(n>0) {
        int temp=n%10;
        ans=ans+temp*temp;
        n/=10;
    }
    return ans;
}
int main(void)
{
    int n,result,ans=0;
    scanf("%d", &n);
    
    result=n;
    while(n>0) {
        result=ff(result);
        n=result/10; 
        
        if(result==1) {
            printf("HAPPY");
            break;
        } else if (n==0) {
            printf("UNHAPPY");
            break;
        }
    }
    
    
    return 0;
}