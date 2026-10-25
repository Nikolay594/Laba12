#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

//int main() {
//    
//    const char* months[] = {
//        "€нвар€", "феврал€", "марта", "апрел€", "ма€", "июн€",
//        "июл€", "августа", "сент€бр€", "окт€бр€", "но€бр€", "декабр€"
//    };
//    time_t t = time(NULL);
//    struct tm* mytime = localtime(&t);
//    printf("“екущее врем€: %02d:%02d:%02d\n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
//    printf("%d %s\n", mytime->tm_mday, months[mytime->tm_mon]);
//    return 0;
//}

int main()
{
    setlocale(LC_ALL, "Russian");
    time_t t = time(NULL);
    struct tm* mytime = localtime(&t);

    int month = mytime->tm_mon + 1;
    int day = mytime->tm_mday;
    int year = mytime->tm_year + 1900;

    int days_in_month[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if ((year % 4 == 0 && year % 100 != 0) ||
        year % 400 == 0)
    {
        days_in_month[1] = 29;
    }

    int days_to_end_month = days_in_month[month - 1] - day;
    int months_to_end_year = 12 - month;

    char str[100];

    printf("“екущее врем€: %02d:%02d:%02d\n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    printf(str, "ƒо конца мес€ца %d дней, до конца года %d мес€цев",
        days_to_end_month, months_to_end_year);

    printf("%s\n", str);

    return 0;
}