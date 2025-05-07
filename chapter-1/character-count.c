#include<stdio.h>

int main(void)
{
	int nc;

	while ((getchar()) != EOF)
		++nc;
	printf("%d\n\n", nc);
}
