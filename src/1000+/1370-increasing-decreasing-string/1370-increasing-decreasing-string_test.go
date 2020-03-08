package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, "cdelotee", sortString("leetcode"))
}

func sortString(s string) string {
	chars := [26]int{}
	for id := range s {
		chars[s[id]-'a']++
	}

	result := ""

	for len(result) < len(s) {
		for id := 0; id < 26; id++ {
			if chars[id] > 0 {
				chars[id]--
				result += string(id + 'a')
			}
		}
		for id := 25; id >= 0; id-- {
			if chars[id] > 0 {
				chars[id]--
				result += string(id + 'a')
			}
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

func inRange(x, low, high int) bool {
	return x >= low && x < high
}
