#include<cstdio>
#include<iostream>
int main(void)
{
    int t,a,b;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", 1+(a-b)*b);
    }
    return 0;
}