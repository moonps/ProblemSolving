#include<cstdio>
int samgak[45], ans[2975];
int main(void) {
    int t; scanf("%d", &t);
    
    for(int i=1; i<45; i++)
        samgak[i]=i*(i+1)/2;
    
    for(int i=1; i<45; i++)
        for(int j=i; j<45; j++)
            for(int k=j; k<45; k++)
                ans[samgak[i]+samgak[j]+samgak[k]]=1;
    
    for(int i=0; i<t; i++) {
        int n; scanf("%d", &n);
        if(ans[n]==1) printf("1\n");
        else printf("0\n");
    }
                
    return 0;
}