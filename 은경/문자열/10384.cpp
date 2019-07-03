#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
int alp[26];
int check[4][26];
int pan[4];
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,i;
    cin>>n;
    cin.ignore();
    for(i=0; i<n; i++) {
        string sstr;
        memset(alp,0,sizeof(alp));
        memset(check,0,sizeof(check));
        memset(pan,0,sizeof(pan));
        
        getline(cin, sstr);
        
        for(int j=0; j<sstr.size(); j++) {
            if (sstr[j]>='a' && sstr[j]<='z') alp[sstr[j]-97]++;
            else if (sstr[j]>='A' && sstr[j]<='Z') alp[sstr[j]-65]++;
        }
        
        for (int j=0; j<26; j++) {
            if (alp[j]>=3) { check[1][j]=1; check[2][j]=1; check[3][j]=1;}
            else if (alp[j]==2) { check[1][j]=1; check[2][j]=1;}
            else if(alp[j]==1)  check[1][j]=1;
        }
    
        for(int j=0; j<4; j++) {
            for(int k=0; k<26; k++) {
                if(check[j][k]==0)
                    pan[j]=1;
            }
        }
         
        if(pan[3]==0) cout<<"Case "<<i+1<<": Triple pangram!!!"<<'\n';
        else if (pan[2]==0) cout<<"Case "<<i+1<<": Double pangram!!"<<'\n';
        else if (pan[1]==0) cout<<"Case "<<i+1<<": Pangram!"<<'\n';
        else cout<<"Case "<<i+1<<": Not a pangram"<<'\n';
    }
    return 0;
}