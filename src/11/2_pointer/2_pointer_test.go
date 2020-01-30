package _11__test

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 49, maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7}))

	n := int(1e7)
	heights := make([]int, 0, n)
	for i := 0; i < n; i++ {
		heights = append(heights, i)
	}
	assert.Equal(t, 24999995000000, maxArea(heights))

}

func maxArea(height []int) int {
	maxArea := 0
	moveHeight := 0
	for i, j := 0, len(height)-1; i < j; {
		hi, hj := height[i], height[j]
		if hi > moveHeight && hj > moveHeight {
			maxArea = maxInt(maxArea, minInt(hi, hj)*(j-i))
		}
		if hi < hj {
			moveHeight = maxInt(hi, moveHeight)
			i++
		} else {
			moveHeight = maxInt(hj, moveHeight)
			j--
		}
	}
	return maxArea
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
