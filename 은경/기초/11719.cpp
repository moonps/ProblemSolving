#include<cstdio>
int main(void)
{
    char c;
    while((c=getchar()) && c!=EOF)
        printf("%c", c);
    return 0;
}