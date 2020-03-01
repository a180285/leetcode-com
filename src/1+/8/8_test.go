package _8

import (
	"github.com/stretchr/testify/assert"
	"math"
	"testing"
)

func Test1(t *testing.T) {
	assert.Equal(t, 42, myAtoi("42"))
	assert.Equal(t, -42, myAtoi("    -42"))
	assert.Equal(t, 4193, myAtoi("4193 with words"))
	assert.Equal(t, 0, myAtoi("words and 987"))
	assert.Equal(t, -2147483648, myAtoi("-91283472332"))
	assert.Equal(t, math.MaxInt32, myAtoi("91283472332"))
}

func myAtoi(str string) int {
	result := 0
	sign := 1
	firstChar := true

	for i := 0; i < len(str); i++ {
		if result > math.MaxInt32+10 {
			break
		}
		ch := str[i]
		if firstChar {
			if ch == ' ' {
				continue
			}
			firstChar = false
			if ch == '+' {
				continue
			} else if ch == '-' {
				sign = -1
			} else if ch >= '0' && ch <= '9' {
				result = int(ch - '0')
			} else {
				break
			}
		} else { // non-first char
			if ch >= '0' && ch <= '9' {
				result = result*10 + int(ch-'0')
			} else {
				break
			}
		}
	}

	result *= sign
	result = maxInt(math.MinInt32, minInt(math.MaxInt32, result))
	return result
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
