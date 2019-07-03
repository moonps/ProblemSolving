#include<cstdio>
#include<iostream>
using namespace std;
int main(void)
{
    int x,y,sum=0,r=0;
    scanf("%d %d", &x, &y);
    if (x != 1) {
        for (int i=(x-1); i>=1; i--)  {
            if (i==2) sum+=28;
            else if ((i==4)||(i==6)||(i==9)||(i==11)) sum+=30;
            else sum+=31;
        }
    }
    sum+=y; r=sum%7;
    if (r==0) printf("SUN");
    else if (r==1) printf("MON");
    else if (r==2) printf("TUE");
    else if (r==3) printf("WED");
    else if (r==4) printf("THU");
    else if (r==5) printf("FRI");
    else printf("SAT");
    return 0;
}