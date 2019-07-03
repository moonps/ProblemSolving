#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k,n; string str;
    cin>> k >> n;
    cin.ignore();
    getline(cin,str);
    k%=26;
    for(int i=0; i<str.size(); i++) {
        if(str[i]>='a' && str[i]<='z') {
            if(str[i]+k<=122) {
                str[i]+=k;
                cout<<str[i];
            } else {
                str[i]=str[i]-(26-k);
                cout<<str[i];
            }
        } else if (str[i]>='A' && str[i]<='Z') {
            if(str[i]+k<=90) {
                str[i]+=k;
                cout<<str[i];
            } else {
                str[i]=str[i]-(26-k);
                cout<<str[i];
            }
        } else {
            cout<<str[i];
        }
        
    }
    return 0;
}
