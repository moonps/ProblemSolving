#include<cstdio>
#include<cstdlib>
]int col[17];
int n,m,ans;
bool isPossible(int c){
    for(int i=0; i<c; i++){
        if(col[i]==col[c])
            return false;
        if(abs(col[i]-col[c])==abs(i-c))
            return false;
    }
    return true;
}
void queen(int i){
    if(i==n)
        ans++;
    
    else{
        for(int j=0;j<n;j++){
            col[i] = j;
            if(isPossible(i))
                queen(i+1);
        }
    }
}
int main(void){
    scanf("%d", &n);
    
    queen(0);
    
    printf("%d",ans);
    return 0;
}