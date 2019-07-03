#include<cstdio>
using namespace std;
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for (int i=1; i<=(2*n-1)/2; i++) {
        for (int j=n-i; j>0; j--)
            printf(" ");
        for (int j=1; j<=(2*i-1); j++)
            printf("*");
        printf("\n");
    }
    for (int i=1; i<=(2*n-1); i++) printf("*");
    printf("\n");
    for (int i=1; i<=(2*n-1)/2; i++) {
        for (int j=1; j<=i; j++)
            printf(" ");
        for (int j=(2*n-1)-(2*i); j>=1; j--)
            printf("*");
        printf("\n");
    }
    return 0;
}