#include <stdio.h>
#include <ctype.h>

#define SIZE 16
void printBinary(short int);

/*counting digits*/

int main()
{
   int c, i, index;
   short flags = 0;
   printf("flags: ");
   printBinary(flags);
   printf("\nEnter your input: ");

   while ((c = getchar()) != EOF)
   {
      if (isdigit(c))
      { // if c is a digit with numerical value n, turn on bit-n in flags
         short n = c - '0';
         flags = flags | 1 << n;
      }
   }
   printf("\nflags: ");
   printBinary(flags);
   printf("\n");

   // output occurences by checking the lower 10 bits one by one
   // hint: at least two approaches
   // you can use one of the idioms mentioned in pdf lab manual, or get hint
   // from the function printBinary() listed below.
   for (i = 0; i <= 9; i++)
   {
      int check = flags & (1 << i); // is bit-i is on or off? i.e., 0 or 1?
      if (check)                    // check != 0
         printf("%d: %s\n", i, "Yes");
      else
         printf("%d: %s\n", i, "No");
   }

   return 1;
}

void printBinary(short int n)
{
   // printf("binary: ");
   int cou = SIZE - 1;
   int k[SIZE] = {0};

   while (n && cou >= 0)
   {
      if (n & 1)     // !=0
         k[cou] = 1; // printf("1");
      else
         k[cou] = 0; // printf("0");

      n >>= 1;
      cou--;
   }
   int i = 0;
   for (; i < SIZE; i++)
   {
      printf("%d", k[i]);
      if ((i + 1) % 8 == 0)
      {
         printf(" ");
      }
   }
}
