#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
float arr[1002];
int main(void)
{
    int n;
    float max,sum=0,avg;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%f", &arr[i]);
    sort(arr,arr+n);
    max=arr[n-1];
    for (int i=0; i<n; i++) {
        arr[i]=(arr[i]/max*100);
        sum+=arr[i];
    }
    avg=sum/n;
    printf("%.2f", avg);
    
    return 0;
}