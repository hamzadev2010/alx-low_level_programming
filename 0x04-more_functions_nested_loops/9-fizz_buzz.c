#include <stdio.h>

/**
 * main - Prints "FizzBuzz" for numbers divisible by both 3 and 5,
 *        "Fizz" for numbers divisible by 3, "Buzz" for numbers divisible by 5,
 *        and the number itself for other numbers from 1 to 100.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;

	n = 1;
	printf("%d", n);
	for (n = 2; n <= 100; n++)
	{
		if ((n % 3 == 0) && (n % 5 == 0))
		{
			printf(" FizzBuzz");
		}
		else if (n % 3 == 0)
		{
			printf(" Fizz");
		}
		else if (n % 5 == 0)
		{
			printf(" Buzz");
		}
		else
		{
			printf(" %d", n);
		}
	}
	printf("\n");
	return (0);
}
