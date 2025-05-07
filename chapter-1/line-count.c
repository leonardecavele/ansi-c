#include<stdio.h>

int main(void)
{
	int nl, c;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			nl++;
	printf("%d\n", nl);
}
