#include<cstdio>
#include<iostream>
char str[1000001];
int alp[26];
using namespace std;
int main(void)
{
    int temp=0,cnt=0,p=0;
    scanf("%s", str);

    for(int i=0; str[i]!='\0'; i++) {
        if(str[i]>='a' && str[i]<='z') alp[str[i]-97]++;
        else if (str[i]>='A' && str[i]<='Z') alp[str[i]-65]++;
    }
 
    for(int i=0; i<26; i++){
        if(temp==alp[i])
            cnt++;
        else if (temp<alp[i]) {
            temp=alp[i];
            cnt=0;
            p=i;
        }
    }
    
    if(cnt==0) printf("%c", p+65);
    else printf("?");
    
    return 0;
}