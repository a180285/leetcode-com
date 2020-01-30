package _9

import (
	"github.com/stretchr/testify/assert"
	"strconv"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, true, isPalindrome(121))
	assert.Equal(t, false, isPalindrome(-121))
}

func isPalindrome(x int) bool {
	str := strconv.Itoa(x)
	for i := 0; i < len(str); i++ {
		if str[i] != str[len(str)-1-i] {
			return false
		}
	}
	return true
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
