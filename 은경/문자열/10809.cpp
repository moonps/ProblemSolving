#include<cstdio>
#include<cstring>
#include<iostream>
int main(void)
{
	char str[100];
	scanf("%s", str);

	int pos['z' + 1];
	memset(pos, -1, sizeof(pos));
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (pos[str[i]] == -1)
			pos[str[i]] = i;
	}

	for (int i = 'a'; i <= 'z'; i++)
		printf("%d ", pos[i]);
	printf("\n");

	return 0;
}
