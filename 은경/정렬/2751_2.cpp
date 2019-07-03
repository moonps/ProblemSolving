#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++)
        printf("%d\n", arr[i]);
    
    return 0;
}