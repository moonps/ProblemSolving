#include<stdio.h>
int main(void)
{
    int x,a,s=0;
    scanf("%d", &x);
    for (int i=0; i<x; i++) {
        scanf("%1d", &a);
        s+=a;
    }
    printf("%d", s);
    return 0;
}