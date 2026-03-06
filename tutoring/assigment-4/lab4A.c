#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINES 34
#define MAX_COLS 54

void print2D(char p[][MAX_COLS], int n);
void exchange2D(char p[][MAX_COLS], int n);
int main()
{
    char inputs[MAX_LINES][MAX_COLS];
    printf("sizeof inputs: %ld\n\n", sizeof inputs);

    /* Read in the lines from the stdin (keyboard) now, using function fgets() */

    int i = 0;
    printf("Enter String: ");
    char tmp[MAX_COLS];
    while (fgets(tmp, MAX_COLS, stdin) != NULL)
    {
        if (strcmp(tmp, "xxx\n") == 0)
        {
            break;
        }
        else
        {
            strcpy(inputs[i], tmp);
        }
        i++;
        printf("Enter String: ");
    }

    printf("\n");

    printf("After while loop Count: %d\n\n", i);
    // displays the array by calling sub-function print2D(...)
    print2D(inputs, i);

    printf("== After swapping ==\n");
    // swaps the first and second row here
    strcpy(tmp, inputs[0]);
    strcpy(inputs[0], inputs[1]);
    strcpy(inputs[1], tmp);

    // calls sub-function exchange2D() to swap some other rows
    exchange2D(inputs, i);

    // displays the (exchanged array) by calling sub-function print2D()

    print2D(inputs, i);

    return 0;
}

// Exchange of rows. need to involve data movement
void exchange2D(char p[][MAX_COLS], int n)
{
    for (int i = 2; i < n - 1; i += 2)
    {

        char tmp[MAX_COLS];
        strcpy(tmp, p[i]);
        strcpy(p[i], p[i + 1]);
        strcpy(p[i + 1], tmp);
    }
}

// output the 2D array, row by row
void print2D(char p[][MAX_COLS], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d]: %s", i, p[i]);
    }
}