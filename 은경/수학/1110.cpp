#include<cstdio>
using namespace std;
int count;
int main(void)
{
    int x,n1,n2,r1,r2;
    scanf("%d", &x);
    r2=x;
    do {
        r1=r2;
        if (r1<10) {
            r2=r1*10+r1; count++;
        }
        else {
            n1=r1/10; n2=r1%10;
            if (n1+n2>=10) {
                r2=(n2*10)+((n1+n2)%10); count++;
            }
            else {
                r2=(n2*10)+(n1+n2); count++;
            }
        }
    } while (x!=r2);
    printf("%d", count);
    return 0;
}