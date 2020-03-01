package _14

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, "fl", longestCommonPrefix([]string{"flower", "flow", "flight"}))
}

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	length := 0
	for {
		if length >= len(strs[0]) {
			break
		}
		ch := strs[0][length]
		for _, str := range strs {
			if length >= len(str) || ch != str[length] {
				return strs[0][:length]
			}
		}
		length++
	}

	return strs[0][:length]
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
