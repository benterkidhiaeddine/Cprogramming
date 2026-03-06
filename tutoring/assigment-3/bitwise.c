#include <stdio.h>

#define SIZE 16

void printBinary(short int n);


int main(){


    /*
    int a = 5;  // 101

    printf("number before right shift %d\n", a);

    a >>= 1; //  it becomes 010 every bit shift to the right by one
    printf("number after right shift %d\n", a);

    a <<= 1; // it becomes 100 every bit shitfs to the left by one
    printf("the number after left shift %d\n", a);
    */

    short flags = 0;

    // turn on the but for the number 5

    printf("the number before turning on the flag for 5: %d\n", flags);
    printf("binary representation of the flags is \n");
    printBinary(flags);
    flags = flags | (2 * 2 * 2 * 2 * 2);

    printf("the number after turning on the flag for 5: %d\n", flags);

    printf("binary representation of the flags is \n");
    printBinary(flags);
    return 0;
}


void printBinary(short int n ){
   //printf("binary: ");
   int cou = SIZE-1;
   int k[SIZE]={0};

   while (n && cou >=0) {
      if (n & 1) // !=0
         k[cou]=1; //printf("1");
      else
         k[cou]=0; //printf("0");

      n >>= 1; 
      cou--;
   }
   int i=0;
   for(; i< SIZE;i++)
   {
      printf("%d", k[i]);
      if ((i+1)%8==0)
      {
         printf(" ");
      }
   }
}