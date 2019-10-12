#include<cstdio>
char arr[52][52];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,max=-1,temp;
void count(){
    for(int i=0; i<n; i++) {
        temp=1;
        for(int j=1; j<n; j++){
            if(arr[i][j]==arr[i][j-1])
                temp++;
            else{
                max=max>temp?max:temp;
                temp=1;
            }
        }
        max=max>temp?max:temp;
    }

    for(int j=0; j<n; j++) {
        temp=1;
        for(int i=1; i<n; i++){
            if(arr[i][j]==arr[i-1][j])
                temp++;
            else{
                max=max>temp?max:temp;
                temp=1;
            }
        }
        max=max>temp?max:temp;
    }
}
void changeCandy(int x, int y) {
    for(int k=0; k<4; k++) {
        int nx=x+dx[k];
        int ny=y+dy[k];
        
        if(0<=nx && nx<n && 0<=ny && ny<n){
            if(arr[x][y]!=arr[nx][ny]) {
                char temp=arr[x][y];
                arr[x][y]=arr[nx][ny];
                arr[nx][ny]=temp;
                count();
                temp=arr[x][y];
                arr[x][y]=arr[nx][ny];
                arr[nx][ny]=temp;
            }
            else
                count();
        }
    }
}
int main(void) {
    scanf("%d\n", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            scanf("%c", &arr[i][j]);
        char temp; scanf("%c", &temp);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            changeCandy(i,j);
    }
    printf("%d", max);
    
    return 0;
}#include<cstdio>
char arr[52][52];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,max=-1,temp;
void count(){
    for(int i=0; i<n; i++) {
        temp=1;
        for(int j=1; j<n; j++){
            if(arr[i][j]==arr[i][j-1])
                temp++;
            else{
                max=max>temp?max:temp;
                temp=1;
            }
        }
        max=max>temp?max:temp;
    }

    for(int j=0; j<n; j++) {
        temp=1;
        for(int i=1; i<n; i++){
            if(arr[i][j]==arr[i-1][j])
                temp++;
            else{
                max=max>temp?max:temp;
                temp=1;
            }
        }
        max=max>temp?max:temp;
    }
}
void changeCandy(int x, int y) {
    for(int k=0; k<4; k++) {
        int nx=x+dx[k];
        int ny=y+dy[k];
        
        if(0<=nx && nx<n && 0<=ny && ny<n){
            if(arr[x][y]!=arr[nx][ny]) {
                char temp=arr[x][y];
                arr[x][y]=arr[nx][ny];
                arr[nx][ny]=temp;
                count();
                temp=arr[x][y];
                arr[x][y]=arr[nx][ny];
                arr[nx][ny]=temp;
            }
            else
                count();
        }
    }
}
int main(void) {
    scanf("%d\n", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            scanf("%c", &arr[i][j]);
        char temp; scanf("%c", &temp);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            changeCandy(i,j);
    }
    printf("%d", max);
    
    return 0;
}