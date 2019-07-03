#include<cstdio>
using namespace std;
int a[8];
int check;
int main(void)
{
    for (int i=0; i<8; i++) scanf(" %d", &a[i]);
    
    for (int i=0; i<7; i++) {
        if ((a[i+1]-a[i]) == 1) check++;
        else if ((a[i+1]-a[i]) == -1) check--;
    }
    if (check == 7) printf("ascending");
    else if (check == -7) printf("descending");
    else printf("mixed");
    
    return 0;
}