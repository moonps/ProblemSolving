#include<iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n,temp,min=1000001,max=-1000001;
    cin>>n;
    while (n--) {
        cin>>temp;
        max=temp>max? temp : max;
        min=temp<min?temp:min;
    }
    cout<<min<<' '<<max;
    return 0;
}