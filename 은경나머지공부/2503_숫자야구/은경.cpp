#include<cstdio>
#include<cstring>
bool arr[1000];
int main(void) {
    int t, cnt=0; scanf("%d", &t);
    memset(arr, true, sizeof(arr));
    
    for (int i = 123; i <= 999; i++) {
        int x,y,z; int temp=i;
        z=temp%10; temp/=10; y=temp%10; x=temp/10;

        if (x == y || x == z || y == z || x==0 || y==0 || z==0) arr[i] = false;
    }
    
    for(int t1=0; t1<t; t1++) {
        int n,s,b,x,y,z; scanf("%d %d %d", &n, &s, &b);
        
        // x:백, y:십, z:일
        z=n%10; n/=10; y=n%10; x=n/10;

        for (int i = 123; i <= 999; i++) {
            int xt,yt,zt; int temp=i,strike=0,ball=0;
            zt=temp%10; temp/=10; yt=temp%10; xt=temp/10;

            if (arr[i]){
                if (z==zt) strike++;
                if (y==yt) strike++;
                if (x==xt) strike++;
                if (z==yt) ball++;
                if (z==xt) ball++;
                if (y==xt) ball++;
                if (y==zt) ball++;
                if (x==yt) ball++;
                if (x==zt) ball++;

                if (strike != s || ball != b)
                    arr[i] = false;
            }
        }
    }

    for (int i = 123; i <= 999; i++) {
        if (arr[i])
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}