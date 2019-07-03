#include<cstdio>
void print_star(int n)
{
    for (int i=1; i<=n; i++)
        printf("* ");
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=n-i; j>=1; j--)
            printf(" ");
        print_star(i);
        printf("\n");
    }
    return 0;
}