#include<stdio.h>
int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			{
			printf("saut de ligne%d\n", c);
			}
		else
			{
			putchar(c);
			printf("%d\n", c);
			}
	}
	return 0;
}

