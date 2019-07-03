#include<cstdio>
#include<iostream>
using namespace std;
float arr[1002];
int main(void)
{
    int n1,n2;
    float cnt,sum,avg,result;
    scanf("%d", &n1);
    for (int i=0; i<n1; i++) {
        sum=0; cnt=0;
        scanf("%d", &n2);
        for (int j=0; j<n2; j++) {
            scanf(" %f", &arr[j]);
            sum+=arr[j];
        }
        avg=sum/n2;
        for (int j=0; j<n2; j++) if(arr[j]>avg) cnt++;
        result=cnt/n2*100;
        printf("%.3f%\n", result); 
    }
    
    return 0;
}