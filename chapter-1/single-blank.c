#include<stdio.h>

int main (void)
{
	int c, temp = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t')
		{
			if (!temp)
			{
				temp = 1;
				fputc(c, stdout);
			}
		}
		else
		{
		fputc(c, stdout);
		temp = 0;
		}
	}
}
