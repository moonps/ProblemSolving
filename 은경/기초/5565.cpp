#include<cstdio>
int arr[10];
int main(void)
{
    int total;
    scanf("%d", &total);
    
    for(int i=0; i<9; i++) {
        scanf("%d", &arr[i]);
        total-=arr[i];
    }
    printf("%d", total);
    return 0;
}