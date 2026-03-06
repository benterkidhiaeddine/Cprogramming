#include <stdio.h>
#include <stdlib.h>

struct results
{
  int data1;
  int data2;
};

void processStruc(struct results);
void printStruc(struct results x);
struct results getSumDiff(int a, int b);

int main()
{
  struct results a = {100, 4};
  printf("Struct a before process: %d %d\n", a.data1, a.data2);
  processStruc(a); // pass by value
  // display a's members again, no change
  printf("Struct a after  process: %d %d\n\n", a.data1, a.data2);

  // functions that return a struct, thus encapsulating multiple values
  /**********************************  */
  int num1, num2;
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2); // Use scanf to enter two values

  // The conditions for the while loop were never specified so I assumed two
  // loop rotations given that there were only two in the sample output
  int i = 1;
  while (1)
  {
    // call getSumDiff() to calculate returns the sum and difference of the two argument integers, as struct results
    // call printStruc () to output sum and diff;
    struct results data = getSumDiff(num1, num2);
    printStruc(data);

    if (i == 2)
    {
      return 0;
    }
    // prompt and read again
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2); // Use scanf to enter two values

    i++;
  }
  return 0;
}

/* call/pass by value  */
void processStruc(struct results x)
{

  x.data1++;
  x.data2 += 100;

  printf("Struct a before process: %d %d\n", x.data1, x.data2);
}

struct results getSumDiff(int a, int b)
{

  struct results data = {a + b, a - b};
  return data;
}

void printStruc(struct results x)
{

  printf("Sum is: %d, Diff is %d\n", x.data1, x.data2);
}
