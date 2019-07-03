#include<cstdio>
int main(void)
{
    int t,a,b,sum;
    
    scanf("%d", &t);
    
    while(t--) {
        sum=0;
        scanf("%d %d", &a, &b);
        if (a==1) sum+=500;
        else if (2<=a && a<=3) sum+=300;
        else if (4<=a && a<=6) sum+=200;
        else if (7<=a && a<=10) sum+=50;
        else if (11<=a && a<=15) sum+=30;
        else if (16<=a && a<=21) sum+=10;

        if( b==1) sum+=512;
        else if (2<=b && b<=3) sum+=256;
        else if (4<=b && b<=7) sum+=128;
        else if (8<=b && b<=15) sum+=64;
        else if (16<=b && b<=31) sum+=32;
        
        sum*=10000;
        printf("%d\n", sum);
    }
    return 0;
}