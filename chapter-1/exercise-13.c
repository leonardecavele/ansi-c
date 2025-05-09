#include<stdio.h>
#include<stdbool.h>

#define IN true
#define MAX_LENGTH 16

int main(void)
{
	int c, state, i = 0;

	state = !IN;
	int lengths[MAX_LENGTH] = {0};
	char buffer[16];

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state)
			{
				lengths[i - 1]++;
				buffer[i] = '\0';
				i = 0;
			}
			state = !IN;
		}
		else
		{
			if (i >= MAX_LENGTH)
			{
				printf("\033[31mError: word above max length.\033[0m\n");
				return 1;
			}
			buffer[i++] = c;
			state = IN;
		}
	}

	if (state)
	{
		buffer[i] = '\0';
		int b = 0;
		while (buffer[b] != '\0')
			b++;
		lengths[b - 1]++;
	}

	int max = 0;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (lengths[i] > max)
			max = lengths[i];
	}

	for (int level = max; level > 0; level--)
	{
		for (int len = 0; len < MAX_LENGTH; len++)
			if (lengths[len] >= level)
				printf(" * ");
			else
				printf("   ");
		putchar('\n');
	}
	for (int len = 1; len <= MAX_LENGTH; len++)
		printf("%2d ", len);
	putchar('\n');
}
