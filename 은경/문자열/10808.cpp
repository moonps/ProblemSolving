#include<cstdio>
#include<cstring>
char arr[101];
int cnt[26];
int main(void)
{
    scanf("%s", arr);
    for(int i=0; arr[i]!='\0'; i++)
        cnt[arr[i]-'a']++;
    
    for(int i=0; i<26; i++)
        printf("%d ", cnt[i]);

    return 0;
}