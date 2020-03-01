package src

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
	"time"
)

func Test1(t *testing.T) {

	assert.Equal(t, 1, daysBetweenDates("2019-06-29", "2019-06-30"))
	assert.Equal(t, 15, daysBetweenDates("2020-01-15", "2019-12-31"))
	assert.Equal(t, 47481, daysBetweenDates("1971-01-01", "2100-12-31"))
}

func daysBetweenDates(date1 string, date2 string) int {
	if date1 > date2 {
		date1, date2 = date2, date1
	}
	if date1 == date2 {
		return 0
	}

	return _daysBetweenDates2(date1, date2)
}

func _daysBetweenDates2(date1 string, date2 string) int {
	days1 := countDays(date1)
	days2 := countDays(date2)
	return days2 - days1
}

func countDays(date string) int {
	var year, month, day int
	fmt.Sscanf(date, "%d-%d-%d", &year, &month, &day)
	days := 0
	for y := 1970; y < year; y++ {
		if isLeapYear(y) {
			days += 366
		} else {
			days += 365
		}
	}
	dayInMonth := []int{
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	}
	for m := 1; m < month; m++ {
		days += dayInMonth[m]
		if isLeapYear(year) && m == 2 {
			days++
		}
	}
	days += day
	return days
}

func isLeapYear(year int) bool {
	if year%4 != 0 {
		return false
	} else if year%400 == 0 {
		return true
	} else if year%100 == 0 {
		return false
	} else {
		return true
	}
}

func _daysBetweenDates1(date1 string, date2 string) int {
	layout := "2006-01-02"
	t1, _ := time.Parse(layout, date1)
	t2, _ := time.Parse(layout, date2)
	return int((t2.Unix() - t1.Unix()) / (60 * 60 * 24))
}

func absInt(x int) int {
	if x < 0 {
		x *= -1
	}
	return x
}

func maxInt(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func minInt(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func make2DInt(r, c int) [][]int {
	s := make([][]int, r)
	for i := 0; i < r; i++ {
		s[i] = make([]int, c)
	}
	return s
}

func inRange(x, low, high int) bool {
	return x >= low && x < high
}
