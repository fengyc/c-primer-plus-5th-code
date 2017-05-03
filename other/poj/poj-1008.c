//
// Created by fengyingcai on 2017/5/3.
//

#include <stdio.h>
#include <string.h>

char *haab_months[] = {
        "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};

char *tzolkin_periods[] = {
        "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};

int getHaabDaysOfYear(char *m, int day)
{
    int i;
    for (i=0; i < 18; i++){
        if (strcmp(m, haab_months[i]) == 0)
            break;
    }
    return day + 20 * i;
}


int main(void)
{
    int n;
    int day;
    char month[20];
    int year;
    long days;
    int period;
    int daysOfYear;


    scanf("%d", &n);
    printf("%d\n", n);
    while (n--)
    {
        scanf("%d. %s %d", &day, month, &year);

        // 转换为 tzolkin
        days = (long)year * 365 + getHaabDaysOfYear(month, day);
        year = days / (13 * 20);
        daysOfYear = days % (13 * 20);
        period = daysOfYear % 20;
        day = daysOfYear % 13 + 1;

        printf("%d %s %d\n", day, tzolkin_periods[period], year);
    }

    return 0;
}
