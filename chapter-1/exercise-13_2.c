#include<stdio.h>

#define MAX_LENGTH 16

void finalize_word(int *lengths, int *i, int *state)
{
	if (*state)
	{
		lengths[(*i) - 1]++;
		*i = 0;
	}
}

int count_word_lengths(int *lengths)
{
	int c, i, state;
	i = state = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			finalize_word(lengths, &i, &state);
			state = 0;
		}
		else
		{
			if (i >= MAX_LENGTH)
			{
				printf("\033[31mError: word above max length.\033[0m\n");
				return 1;
			}
			i++;
			state = 1;
		}
	}
	finalize_word(lengths, &i, &state);
	return 0;
}

int find_max(int *lengths)
{
	int max = 0;
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (lengths[i] > max)
			max = lengths[i];
	}
	return max;
}

void print_histogram(int max, int *lengths)
{
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

int main(void)
{
	int lengths[MAX_LENGTH] = {0};

	if (count_word_lengths(lengths))
		return 1;

	print_histogram(find_max(lengths), lengths);
	return 0;
}
