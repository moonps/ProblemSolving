#include<cstdio>
int main(void) {
    int t; scanf("%d", &t);
    for(int x=0; x<t; x++) {
        int n; scanf("%d", &n);
        bool check=false;
        
        for(int i=1; i<=n; i++) {
            if(!check) {
                for(int j=1; j<=n; j++) {
                    if(!check){
                        for(int k=1; k<=n; k++) {
                            if(!check) {
                                if (n == (i*(i+1)/2) +(j*(j+1)/2)+(k*(k+1)/2)){
                                    printf("1\n");
                                    check=true;
                                    break;
                                }
                            } else break;
                    	}
                	} else break;
            	}
            } else break;
        }
        if(!check)
            printf("0\n");
    }
    return 0;
}