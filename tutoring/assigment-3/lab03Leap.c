#include <stdio.h>

enum months
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

int isLeap(int year);
int countDays(int month, int day, int isLeap);

int main()
{

    int year;
    int month;
    int day;

    int is_leap_year;

    printf("Enter date ('YYYY MM DD'): ");
    scanf("%d %d %d", &year, &month, &day);

    while (year > 0)
    {
        int is_leap = isLeap(year);
        int elapsed_days = countDays(month, day, is_leap);
        printf("%d days of year %d have elapsed ", elapsed_days, year);

        if (is_leap != 0)
        {
            printf("[leap year]\n");
        }
        printf("\n");

        printf("Enter date ('YYYY MM DD'): ");
        scanf("%d %d %d", &year, &month, &day);
    }
    return 0;
}

int isLeap(int year)
{

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int countDays(int month, int day, int isLeap)
{
    int result = 0;

    for (int i = 1; i < month; i++)
    {
        if (i == JAN || i == MAR || i == MAY || i == JUL || i == AUG || i == OCT || i == DEC)
        {
            result += 31;
        }
        else if (i == APR || i == JUN || i == SEP || i == NOV)
        {
            result += 30;
        }
        else if (i == FEB)
        {
            if (isLeap == 0)
            {
                result += 28;
            }
            else
            {
                result += 29;
            }
        }
    }
    result += day;
    return result;
}
