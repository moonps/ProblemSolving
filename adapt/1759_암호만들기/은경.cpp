// 1759
#include<cstdio>
#include<algorithm>
using namespace std;
char arr[17];
bool check[26];
int state[17];
int x,y,l,c,cur=0;
void checkAlpha(int node) {
    if(arr[node]=='a'|arr[node]=='e'|arr[node]=='i'|arr[node]=='o'|arr[node]=='u'){
        state[cur++]=0;
        x++;
    } else {
        state[cur++]=1;
        y++;
    }
}
void secret(int node, int cnt) {
    if(cnt==l) {
        if(x>=1 && y>=2) {
            for(int i=0; i<26; i++)
                if(check[i])
                    printf("%c",arr[i]);
            printf("\n");
        }
        return;
    } if(node>=c)
        return;
    
    checkAlpha(node);
    check[node]=true;
    secret(node+1, cnt+1);
    
    // 아닐경우 돌아가야하니까
    if(state[cur-1]==0) { x--; cur--;}
    else { y--; cur--;}
    check[node]=false;
    secret(node+1, cnt);
}
int main(void) {
    scanf("%d %d", &l, &c);
    for(int i=0; i<c; i++) {
        scanf(" %c", &arr[i]);
    }
    sort(arr, arr+c);
    secret(0,0);
    
    return 0;
}
