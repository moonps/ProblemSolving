#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    int n,b;
    scanf("%d %d", &n,&b);
    string sstr;
    while(n>0) {
        int r=n%b;
        if(r<10)
            sstr+=(char)(r+'0');
        else
            sstr+=(char)(r-10+'A');
        n/=b;
    }
    reverse(sstr.begin(), sstr.end());
    cout<<sstr<<'\n';
    return 0;
}