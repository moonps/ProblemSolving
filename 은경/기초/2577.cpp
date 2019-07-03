#include<cstdio>
using namespace std;
int arr[10];
int main(void)
{
    int a,b,c,r;
    scanf(" %d %d %d", &a, &b, &c);
    r=a*b*c;
    while(r>10) {
        arr[r%10]++;
        r/=10;
    }
    arr[r]++;
    
    for (int i=0; i<10; i++) printf("%d\n", arr[i]);
    return 0;
}