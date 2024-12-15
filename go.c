package main

import (
    "fmt"
    "time"
)

// 判断是否为闰年
func isLeapYear(year int) bool {
    return (year%4 == 0 && year%100!= 0) || year%400 == 0
}

// 获取指定月份的天数
func getDaysInMonth(year int, month int) int {
    days := 31
    if month == 4 || month == 6 || month == 9 || month == 11 {
        days = 30
    } else if month == 2 {
        if isLeapYear(year) {
            days = 29
        } else {
            days = 28
        }
    }
    return days
}

// 获取1900年1月1日到指定日期的总天数
func getTotalDaysFrom1900(year int, month int, day int) int {
    totalDays := 0
    for y := 1900; y < year; y++ {
        if isLeapYear(y) {
            totalDays += 366
        } else {
            totalDays += 365
        }
    }
    for m := 1; m < month; m++ {
        totalDays += getDaysInMonth(year, m)
    }
    totalDays += day
    return totalDays
}

// 打印日历头部，即星期信息
func printCalendarHeader() {
    fmt.Println("Sun Mon Tue Wed Thu Fri Sat")
}

// 打印日历主体内容
func printCalendarBody(year int, month int) {
    daysInMonth := getDaysInMonth(year, month)
    firstDayTotalDays := getTotalDaysFrom1900(year, month, 1)
    firstDayWeekday := (firstDayTotalDays + 1) % 7
    for i := 0; i < int(firstDayWeekday); i++ {
        fmt.Printf("    ")
    }
    for d := 1; d <= daysInMonth; d++ {
        fmt.Printf("%3d ", d)
        if (firstDayWeekday+d)%7 == 6 {
            fmt.Println()
        }
    }
    if (firstDayWeekday+daysInMonth)%7!= 6 {
        fmt.Println()
    }
}

func main() {
    var year, month int
    fmt.Print("请输入年份: ")
    fmt.Scan(&year)
    fmt.Print("请输入月份: ")
    fmt.Scan(&month)
    if month < 1 || month > 12 {
        fmt.Println("输入的月份不合法，请重新输入")
        return
    }
    printCalendarHeader()
    printCalendarBody(year, month)
}
