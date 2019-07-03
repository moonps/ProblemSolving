#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    string sstr;
    int b,ans=0;
    cin>>sstr>>b;
    
    for(int i=0; i<sstr.size(); i++) {
        if('0'<=sstr[i] && sstr[i]<='9')
            ans=ans*b+(sstr[i]-'0');
        else
            ans=ans*b+(sstr[i]-'A'+10);
    }
    cout<<ans<<'\n';
    return 0;
}