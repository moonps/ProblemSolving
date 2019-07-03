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

    string arr;
    getline(cin,arr);
    
    for(int i=0; arr[i]!='\0'; i++) {
        if(arr[i]>='a' && arr[i]<='z')
            arr[i]=(arr[i]-'a'+13)%26+'a';
        else if(arr[i]>='A' && arr[i]<='Z')
            arr[i]=(arr[i]-'A'+13)%26+'A';
    }
    
    for(int i=0; arr[i]!='\0'; i++)
        cout<<arr[i];
    
    return 0;
}