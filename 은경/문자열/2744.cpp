#include<cstdio>
#include<cstring>
char cstr[102];
int main(void) {
    scanf("%s", cstr);

    for(int i=0; cstr[i]!='\0'; i++) {
        if('a'<=cstr[i] && cstr[i]<='z') printf("%c", cstr[i]-32);
        else if ('A'<=cstr[i] && cstr[i]<='Z') printf("%c", cstr[i]+32);
    }
    return 0;
}