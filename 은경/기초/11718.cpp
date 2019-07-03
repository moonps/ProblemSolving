#include<cstdio>
char s[111];
int main(void)
{
    while (scanf("%[^\n]\n", s)==1)
        printf("%s\n", s);
    return 0;
}