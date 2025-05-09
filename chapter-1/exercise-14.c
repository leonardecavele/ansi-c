#include<stdio.h>

int main(void)
{
	int c, i = 0;
	int frequencies[127] = {0};

	while ((c = getchar()) != EOF)
	{
		if (c >= 0 && c < 127)
		frequencies[c]++;
	}

	while (i < 127)
	{
		if (frequencies[i] > 0)
		{
			printf("%3d  ", i);
			if (i == '\t')
				printf("\\t ");
			else if (i == '\b')
				printf("\\b ");
			else if (i == '\\')
				printf("\\\\ ");
			else if (i == '\n')
				printf("\\n ");
			else
				printf(" %c ", i);
			printf("  ");
		}
		int j = 0;
		while (frequencies[i] > j)
		{
			putchar('*');
			j++;
		}
		if (frequencies[i] > 0)
		putchar('\n');
		i++;
	}
	return 0;
}
