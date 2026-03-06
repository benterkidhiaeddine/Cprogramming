#include <stdio.h>

// Include other directives if needed
#include <stdlib.h>
#include <string.h>

// Function Prototypes

int getSum(char *args[], int n);
int getDiff(char *args[], int n);
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s [sum|diff] int1 int2 ...\n", argv[0]);
        return 1;
    }

    // Display the number of arguments (excluding executable name)
    printf("Total arguments: %d\n", argc - 1);

    // Check if the first argument is "sum" or "diff"

    if (strcmp(argv[1], "sum") == 0)
    {
        printf("Calculating sum: ");
        printf("%s", argv[2]);
        for (int i = 3; i < argc; i++)
        {
            printf(" + %s", argv[i]);
        }
        printf(" = %d\n", getSum(argv, argc));
    }
    else if (strcmp(argv[1], "diff") == 0)
    {
        printf("Calculating difference: ");
        printf("%s", argv[2]);
        for (int i = 3; i < argc; i++)
        {
            printf(" - %s", argv[i]);
        }
        printf(" = %d\n", getDiff(argv, argc));
    }
    else
    {
        printf("Invalid operation. Use either \'sum\' or \'diff\'\n");
    }

    return 0;
}
// Function to calculate the sum of integers
int getSum(char *args[], int n)
{

    int sum = 0;
    for (int i = 2; i < n; i++)
    {
        sum += atoi(args[i]);
    }
    return sum;
}

// Function to calculate the difference of integers
int getDiff(char *args[], int n)
{

    int diff = atoi(args[2]);
    for (int i = 3; i < n; i++)
    {
        diff -= atoi(args[i]);
    }
    return diff;
}