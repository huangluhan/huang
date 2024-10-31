
#include <stdio.h>
#include <math.h>

int abs(int n) {
    return n >= 0? n : -n;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100!= 0) || year % 400 == 0;
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return days[month - 1];
}

int daysSinceAD1(int year, int month, int day) {
    int days = 0;
    for (int y = 1; y < year; y++) {
        days += isLeapYear(y)? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += daysInMonth(m, year);
    }
    return days + day - 1;
}

int dayBetweenTwo(int year1, int month1, int day1, int year2, int month2, int day2) {
    int days1 = daysSinceAD1(year1, month1, day1);
    int days2 = daysSinceAD1(year2, month2, day2);
    return days1 - days2;
}

int findDayOfWeek(int year, int month, int day) {
    int referenceYear = 2024;
    int referenceMonth = 10;
    int referenceDay = 29;
    int daysDiff = dayBetweenTwo(year, month, day, referenceYear, referenceMonth, referenceDay);
    int dayOfWeek = (daysDiff + 2) % 7;
    if (daysDiff < 0) {
        dayOfWeek = (7 + dayOfWeek) % 7;
    }
    return dayOfWeek;
}

void calendar(int dayOfWeek, int days) {
    int i, j;
    printf("日 一 二 三 四 五 六\n");
    for (i = 0; i < dayOfWeek; i++) {
        printf("   ");
    }
    for (j = 1; j <= days; j++) {
        printf("%2d ", j);
        if ((j + dayOfWeek) % 7 == 0)
            printf("\n");
    }
}

int main() {
    int year, month, day;
    printf("请输入年份：");
    scanf("%d", &year);
    printf("请输入月份:");
    scanf("%d",&month);
    int dayOfWeek = findDayOfWeek(year, month, 1);
    int days = daysInMonth(month, year);
    printf("%d 月\n", month);
    calendar(dayOfWeek, days);
    printf("\n") ;  
    return 0;
}

