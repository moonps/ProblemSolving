#include <cstdio>
using namespace std;
const int mod = 1000000;
const int p = mod/10*15;
int fibo[p] = {0,1};
int main() {
    long long n;
    scanf("%lld", &n);
    for (int i=2; i<p; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= mod;
    }
    printf("%d", fibo[n%p]);
    return 0;
}