#include<stdio.h>
int D(int n)
{
    int i=0,j,r,z;
    
    if (n < 10)
        return n + n;
    
    z = n;
    for (z; z >= 10; ) {
        z /= 10;
        i++;
    }
    
    z = n;
    for (j = 0; j <=i; j++) {
        n += (z % 10);
        z=z / 10;
    }
    
    return n;
}

int main(void)
{
    char a[100001] = { 0 };
    
    for (int i = 1; i <= 10000; i++) {
        a[D(i)] = 1;
        
        if (a[i] == 0)
            printf("%d\n", i);
    }
    
    return 0;
}
