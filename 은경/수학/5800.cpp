#include<cstdio>
#include<algorithm>
using namespace std;
int arr[101][52];
int main(void) {
    int k;
    scanf("%d", &k);
    
    for(int i=1; i<=k; i++) {
        int n,gap=0; scanf(" %d", &n);
        for(int j=1; j<=n; j++)
            scanf(" %d", &arr[i][j]);
        sort(arr[i], arr[i]+1+n);
        for(int j=n; j>1; j--) {
            if(arr[i][j]-arr[i][j-1]>gap)
                gap=arr[i][j]-arr[i][j-1];
        }
        printf("Class %d\n", i);
        printf("Max %d, Min %d, Largest gap %d\n", arr[i][n], arr[i][1], gap);
    }
    return 0;
}