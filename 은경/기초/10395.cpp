#include<cstdio>
int a[5];
int b[5];
int main(void)
{
    int ans=0;
    for(int i=0; i<5; i++) scanf("%d", &a[i]);
    for(int i=0; i<5; i++) scanf("%d", &b[i]);
    
    for(int i=0; i<5; i++) {
        if(a[i]==b[i]) {
            ans=1;
            break;
        }
    }
    if(ans==1) printf("N");
    else printf("Y");
    
    return 0;
}