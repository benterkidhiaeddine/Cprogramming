#include <stdio.h> // define EOF

int main()
{
  int c;
  int count = 0;

  c = getchar();
  while (c != EOF) /* no end-of-file yet */
  {
    count++; // spaces and '\n' also counted

    c = getchar(); /* read next */
  }
  printf("# of chars: %d\n", count);
}
