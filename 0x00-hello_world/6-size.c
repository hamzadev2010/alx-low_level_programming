#include <stdio.h>
/**
 * main - Entry point of the program
 *
 * Return: 0 (Success)
 */
int main(void)
{
char a;
int b;
long int c;
long long int d;
float f;
printf("Size of char: %lu byte(s)\n", (unsigned long)sizeof(a));
printf("Size of int: %lu byte(s)\n", (unsigned long)sizeof(b));
printf("Size of long int: %lu byte(s)\n", (unsigned long)sizeof(c));
printf("Size of long long int: %lu byte(s)\n", (unsigned long)sizeof(d));
printf("Size of float: %lu byte(s)\n", (unsigned long)sizeof(f));
#ifdef __x86_64__
printf("System is 64-bit\n");
#elif defined(__i386__)
printf("System is 32-bit\n");
#else
printf("System architecture is unknown\n");
#endif
return (0);
}
