#include<stdio.h>
int main(void)
{
	int num, rest, x, y, a, b;
	scanf("%d", &num);

	if (num == 3)
		printf("1");

	else if (num % 5 == 0)
		printf("%d", num / 5);

	else {
		x = num / 5;

		for (int i = 0; i < x; i++) {
			x = (num - (num % 5)) - (5 * i); 
			y = (num % 5) + (5 * i);

			if (y % 3 == 0) {
				printf("%d", (x / 5) + (y / 3));
				exit(0);
			}
		}
		printf("-1");
	}

	return 0;
}