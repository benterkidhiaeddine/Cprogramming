#include <stdio.h>
#include <stdlib.h> // for atoi
#include <string.h> // for atoi

#define SIZE 14

int my_atoi(char c[]);
int power(int base, int n);
int toInt(char c);

int main()
{
  int a, b;
  char arr[SIZE];

  printf("Enter a word of positive number or 'quit': ");
  scanf("%s", arr);
  while (strcmp(arr, "quit") != 0)
  {
    printf("%s\n", arr);

    a = atoi(arr);
    printf("atoi:    %d (%#o, %#X)\t%d\t%d\n", a, a, a, a * 2, a * a);

    b = my_atoi(arr);
    printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n", b, b, b, b * 2, b * b);
    printf("Enter a word of positive number or 'quit': ");
    scanf("%s", arr);
  }

  return 0;
}

/* converts an array of (digit) characters into a decimal value*/
int my_atoi(char c[])
{
  int len = strlen(c);
  int currentPower = 0;
  int result = 0;

  for (int i = len - 1; i > -1; i--)
  {
    result += toInt(c[i]) * power(10, currentPower);
    currentPower++;
  }
  return result;
}

int power(int base, int n)
{
  int result = 1;
  for (int i = 0; i < n; i++)
  {
    result *= base;
  }
  return result;
}

int toInt(char c)
{
  return c - '0';
}