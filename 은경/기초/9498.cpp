#include<cstdio>
int main(void)
{
    int s;
    scanf("%d", &s);
    if (90<= s && s <=100) printf("A");
    else if (80<=s && s<=89) printf("B");
    else if (70<=s && s<=79) printf("C");
    else if (60<=s && s<=69) printf("D");
    else printf("F");
    return 0;
}