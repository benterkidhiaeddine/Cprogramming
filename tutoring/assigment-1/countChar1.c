#include <stdio.h> // define EOF

int main()
{
  int c;
  int count = 0;
  int line_count = 0;
  int blank_count = 0;

  c = getchar();
  while (c != EOF) /* no end-of-file yet */
  {

    c = getchar(); /* read next */
    if (c == '\n')
    {
      line_count += 1;
      continue;
    }
    else if (c == ' ')
    {
      blank_count += 1;
    }
    count++; // spaces and '\n' also counted
  }
  printf("# of chars: %d, (# of blanks: %d)\n", count, blank_count);
  printf("# of lines: %d\n", line_count);
}
