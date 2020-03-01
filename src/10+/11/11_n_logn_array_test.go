package _11_test

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test2(t *testing.T) {

	assert.Equal(t, 49, maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7}))
	assert.Equal(t, 1, maxArea([]int{1, 1}))

	n := int(1e7)
	heights := make([]int, 0, n)
	for i := 0; i < n; i++ {
		heights = append(heights, i)
	}
	assert.Equal(t, 24999995000000, maxArea(heights))
}

type Stack struct {
	index  int
	height int
}

func maxArea(height []int) int {
	result := _maxArea(height)
	reverseInts(height)
	result = maxInt(result, _maxArea(height))
	return result
}

func _maxArea(height []int) int {
	area := 0
	stacks := make([]Stack, 0, len(height)+10)
	stacks = append(stacks, Stack{-1, 0})
	for i := 0; i < len(height); i++ {
		h := height[i]
		if stacks[len(stacks)-1].height < h {
			stacks = append(stacks, Stack{i, h})
		}

		idx := upper(stacks, h)
		//fmt.Println(stacks, "idx", idx, "h", h)
		area = maxInt(area, (i-stacks[idx].index)*h)
	}
	return area
}

func upper(stacks []Stack, v int) int {
	if len(stacks) <= 16 {
		for i := 0; i < len(stacks); i++ {
			if stacks[i].height >= v {
				return i
			}
		}
	}
	l, h := 0, len(stacks)-1

	for l < h {
		mid := h - (h-l+1)/2
		if stacks[mid].height >= v {
			h = mid
		} else {
			l = mid + 1
		}
	}
	return h
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

func reverseInts(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
