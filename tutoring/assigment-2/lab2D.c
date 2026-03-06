#include <stdio.h>
// include string library header files
#include <string.h>
// more declarations as needed

#define SIZE 35
void my_strcat(char des[], char src[]);

int main()
{
   char a[SIZE];
   char b[SIZE];
   char c[SIZE];
   char d[SIZE];

   printf("Enter the first string(with no spaces) stored in array 'a': ");
   scanf("%s", a);

   printf("Enter the first string(with no spaces) stored in array 'b': ");
   scanf("%s", b);

   // Complete the Code
   while (strcmp(a, "xxx") != 0 || strcmp(b, "xxx") != 0)
   {

      strcpy(c, a);
      strcpy(d, b);

      strcat(a, b);
      my_strcat(c, d);

      printf("Original function strcat(a,b) results:   %s\n", a);
      printf("My function my_strcat(c,d) results: %s\n\n", c);

      // Take the inputs again till you enter "xxx" for both arrays

      printf("Enter the first string(with no spaces) stored in array 'a': ");
      scanf("%s", a);

      printf("Enter the first string(with no spaces) stored in array 'b': ");
      scanf("%s", b);
   }
}

// your version of strcat implementation here
void my_strcat(char des[], char src[])
{
   int des_len = strlen(des);
   int src_len = strlen(src);
   printf("the source len is %d , and the dest len is %d\n", src_len, des_len);

   for (int i = 0; i < src_len; i++)
   {
      des[des_len + i] = src[i];
   }
   des[des_len + src_len] = '\0';
}
