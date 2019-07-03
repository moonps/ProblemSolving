#include<cstdio>
int arr[11];
int main(void)
{
    int n,i,temp1=1,temp2=1,ans=0;
    scanf("%d", &n);
    
    for(i=0; n>=1; i++) {
        arr[i]=n%10;
        n/=10;
    }
    
    for(int j=0; j<i-1; j++) {
        temp2=1;
        for (int k=j+1; k<i; k++) {
            temp2*=arr[k];
        }
        temp1*=arr[j];
        if(temp1==temp2) {
            ans=1;
            break;
        }
    }
    
    if(ans==1) printf("YES");
    else printf("NO");
    
    return 0;
}