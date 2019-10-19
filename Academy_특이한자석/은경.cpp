#include<cstdio>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;
vector<pair<int, int>> v;
int arr[5][10];
int is_move[5];
// 돌리자
void circle(){
    for(int i=1; i<=4; i++){
        if(is_move[i]==1){
            int temp=arr[i][8];
            for(int j=7; j>=1; j--){
                arr[i][j+1]=arr[i][j];
            }
            arr[i][1]=temp;
        } else if (is_move[i]== -1){
            int temp=arr[i][1];
            for(int j=2; j<=8; j++){
                arr[i][j-1]=arr[i][j];
            }
            arr[i][8]=temp;
        }
    }
}
// 돌려야되는지 확인
void check_arr(int num, int dir){
    is_move[num]=dir;
    
    for(int i=num; i<=3; i++){
        if(arr[i][3]!=arr[i+1][7])
            is_move[i+1]=is_move[i]*-1;
        else
            break;
    }
    for(int i=num; i>=2; i--){
        if(arr[i][7]!=arr[i-1][3])
            is_move[i-1]=is_move[i]*-1;
        else
            break;
    }
    circle();
    memset(is_move,0,sizeof(is_move));
}
int main(void){
    int t; scanf("%d", &t);
    
    for(int tc=1; tc<=t; tc++){
        int k; scanf("%d", &k);
        
        for(int i=1; i<=4; i++){
            for(int j=1; j<=8; j++)
                scanf("%d", &arr[i][j]);
        }
        
        for(int i=1; i<=k; i++) {
            int a,b; scanf("%d %d", &a, &b);
            v.push_back(make_pair(a,b));
        }
        
        for(int i=0; i<v.size(); i++)
            check_arr(v[i].first, v[i].second);
       
        v.clear();
       
        
        int sum=0;
        
        for(int i=1; i<=4; i++){
            if(arr[i][1]==1)
                sum+=pow(2,i-1);
        }

        printf("#%d %d\n", tc, sum);
    }
    return 0;
}