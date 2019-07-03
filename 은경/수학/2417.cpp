#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unsigned long long num,result;
    cin>>num;
    result=sqrtl(num);
    
    if(pow(result,2)<num)
        cout<<result+1;
    else
        cout<<result;
    
    return 0;
}