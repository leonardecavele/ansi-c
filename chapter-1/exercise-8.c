#include<stdio.h>

int main(void)
{
	int c, blanks = 0, tabs = 0, nl = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			blanks++;
		else if (c == '\t')
			tabs++;
		else if (c == '\n')
			nl++;
	}
	printf("There are %d blanks\nThere are %d tabs\nThere are %d newlines\n", blanks, tabs, nl);
}
