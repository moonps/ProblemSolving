#include<cstdio>
char arr[52][52];
int m,n,ans_min=65,cnt;
void white(int x, int y){
    cnt=0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(i%2==0 && j%2==0 && arr[i+x][j+y]!='W')
                cnt++;
            else if (i%2==0 && j%2!=0 && arr[i+x][j+y]!='B')
                cnt++;
            else if (i%2!=0 && j%2==0 && arr[i+x][j+y]!='B')
                cnt++;
            else if (i%2!=0 && j%2!=0 && arr[i+x][j+y]!='W')
                cnt++;
        }
    }
}
void black(int x, int y){
    cnt=0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(i%2==0 && j%2==0 && arr[i+x][j+y]!='B')
                cnt++;
            else if (i%2==0 && j%2!=0 && arr[i+x][j+y]!='W')
                cnt++;
            else if (i%2!=0 && j%2==0 && arr[i+x][j+y]!='W')
                cnt++;
            else if (i%2!=0 && j%2!=0 && arr[i+x][j+y]!='B')
                cnt++;
        }
    }
}
int main(void) {
    scanf("%d %d\n", &m, &n);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            scanf("%c", &arr[i][j]);
        char temp; scanf("%c", &temp);
    }
    
    for(int i=0; i<=m-8; i++){
        for(int j=0; j<=n-8; j++) {
            white(i,j);
            ans_min=ans_min<cnt?ans_min:cnt;
            black(i,j);
            ans_min=ans_min<cnt?ans_min:cnt;
        }
    }
    printf("%d", ans_min);
    return 0;
}