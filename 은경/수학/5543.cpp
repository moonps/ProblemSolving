#include <iostream>
#include <algorithm>
using namespace std;
int a[3],b[2];
int main()
{
    for(int i=0;i<3;i++)
        scanf("%d", &a[i]);
    
    for(int i=0; i<2; i++)
        scanf("%d", &b[i]);
    sort(a,a+3);
    sort(b,b+2);
    printf("%d", a[0]+b[0]-50);
}