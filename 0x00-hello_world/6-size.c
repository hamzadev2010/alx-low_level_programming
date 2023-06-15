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
printf("Size of char: %d  byte(s)\n", (unsigned long)sizeof(a));
printf("Size of int: %d  byte(s)\n", (unsigned long)sizeof(b));
printf("Size of long int: %d byte(s)\n", (unsigned long)sizeof(c));
printf("Size of long long int: %d byte(s)\n", (unsigned long)sizeof(d));
printf("Size of float: %d  byte(s)\n", (unsigned long)sizeof(f));
#if defined(__LP64__) || defined(_LP64)
printf("Machine architecture: 64-bit\n");
#else
printf("Machine architecture: 32-bit\n");
#endif
return (0); }
