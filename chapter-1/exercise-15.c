#include<stdio.h>

#define lower 0
#define upper 300
#define step 20

void print_fctable()
{
	float celsius, fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr+= step;
	}
}

int main(void)
{
	print_fctable();

	return 0;
}
