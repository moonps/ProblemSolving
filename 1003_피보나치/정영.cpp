//
//  main.cpp
//  fibo
//
//  Created by USER on 03/07/2019.
//  Copyright © 2019 USER. All rights reserved.
//

#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    scanf("%d",&T);
    int dp[50][2] = {0,};
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i < 41; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    while(T--){
        int target;
        scanf("%d",&target);
        printf("%d %d\n",dp[target][0], dp[target][1]);
    }
    return 0;
}
