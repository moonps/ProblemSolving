#include<cstdio>
int size;
void print_star1(int n)
{
    for (int j=size-n; j>=1; j--)
        printf(" ");
    printf("*\n");
}
void print_star2(int k,int n)
{
    for(int i=k; i>=1; i--)
        printf(" ");
    printf("*");
    for(int i=1; i<=2*(n-1)-1; i++)
        printf(" ");
    printf("*\n");
}
void print_star3(int n)
{
    for(int j=1; j<=2*n-1; j++)
        printf("*");
    printf("\n");
}
int main(void)
{
    scanf("%d", &size);
    if(size==1) printf("*");
    else {
        for(int i=1; i<=size; i++) {
            if(i==1) print_star1(i);
            
            else if (1<i && i<size) {
                int k=size-i;
                print_star2(k,i);
            }
            
            if(i==size) print_star3(i);
        }
    }
    return 0;
}