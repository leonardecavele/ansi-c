#include<stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	int c, state, i;
	c = state = 0;

	char buffer[32];
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN)
			{
				buffer[i] = '\0';
				printf("%s\n", buffer);
				i = 0;
			}
			state = OUT;
		}
		else
		{
			state = IN;
			buffer[i++] = c;
		}
	}
	return 0;
}
