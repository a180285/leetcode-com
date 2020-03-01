package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 10, numberOfSubstrings("abcabc"))
	assert.Equal(t, 0, numberOfSubstrings("a"))
}

func numberOfSubstrings(s string) int {
	count := 0
	indexes := [3]int{-1, -1, -1}

	for i := 0; i < len(s); i++ {
		indexes[s[i]-'a'] = i
		minId := minInt(indexes[0], indexes[1])
		minId = minInt(minId, indexes[2])
		count += minId + 1
	}
	return count
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
