package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	// [0,1,0,2,1,0,1,3,2,1,2,1]

	assert.Equal(t, 6, trap([]int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}))
}

func trap(height []int) int {
	if len(height) == 0 {
		return 0
	}
	left := make([]int, len(height))
	right := make([]int, len(height))

	left[0] = height[0]
	for i := 1; i < len(height); i++ {
		left[i] = maxInt(left[i-1], height[i])
	}
	lastId := len(height) - 1
	right[lastId] = height[lastId]
	for i := lastId - 1; i >= 0; i-- {
		right[i] = maxInt(right[i+1], height[i])
	}

	water := 0
	for i := 0; i < len(height); i++ {
		water += minInt(left[i], right[i]) - height[i]
	}

	return water
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
