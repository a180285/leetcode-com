package _32

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 2, longestValidParentheses("(()"))
	assert.Equal(t, 4, longestValidParentheses(")()())"))
	assert.Equal(t, 6, longestValidParentheses("))(())()"))
}

func longestValidParentheses(s string) int {
	s = ")" + s
	lvp := make([]int, len(s))
	result := 0

	for i := 1; i < len(s); i++ {
		if s[i] == '(' {
			lvp[i] = 0
		} else if s[i-1-lvp[i-1]] == '(' {
			lvp[i] = 2 + lvp[i-1] + lvp[i-2-lvp[i-1]]
			result = maxInt(result, lvp[i])
		} else {
			lvp[i] = 0
		}
	}

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
