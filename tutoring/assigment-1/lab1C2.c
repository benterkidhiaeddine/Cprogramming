#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int isPrime(int num);

int main()
{
  int i;
  int arr[SIZE];
  srand(time(0));
  for (i = 0; i < SIZE; i++)
  {
    int ran = rand() % 41; // a random number that's in the range of [0,40] inclusive
    arr[i] = ran;
  }

  // display the array
  printf("array [ ");
  for (int i = 0; i < SIZE; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("]\n");
  // create two arrays of the same size of arr, one to hold even numbers and one for prime numbers;
  // scan the array to find even and prime numbers, and put them in corresponding arrays
  // you may add other variables as needed
  int primes[SIZE];
  int evens[SIZE];
  int primeCounter = 0;
  int evenCounter = 0;

  for (int i = 0; i < SIZE; i++)
  {
    if (arr[i] % 2 == 0)
    {
      evens[evenCounter] = arr[i];
      evenCounter++;
    }
    if (isPrime(arr[i]) == 1)
    {
      primes[primeCounter] = arr[i];
      primeCounter++;
    }
  }
  // output the even numbers
  printf("%d even numbers: ", evenCounter);
  for (int i = 0; i < evenCounter; i++)
  {
    printf("%d ", evens[i]);
  }
  printf("\n");

  // output the prime numbers
  printf("%d prime numbers: ", primeCounter);
  for (int i = 0; i < primeCounter; i++)
  {
    printf("%d ", primes[i]);
  }
  printf("\n");
}

int isPrime(int num)
{

  if (num == 0 || num == 1)
  {
    return 0;
  }
  for (int i = 2; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      return 0;
    }
  }
  return 1;
}
