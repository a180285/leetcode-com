package _266_Minimum_Time_Visiting_All_Points

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {
	// Input: points =
	// Output: 7

	points := [][]int{
		{1, 1},
		{3, 4},
		{-1, 0},
	}

	assert.Equal(t, 7, minTimeToVisitAllPoints(points))
}

func minTimeToVisitAllPoints(points [][]int) int {
	t := 0

	for i := 1; i < len(points); i++ {
		deltaX := absInt(points[i][0] - points[i-1][0])
		deltaY := absInt(points[i][1] - points[i-1][1])

		t += maxInt(deltaX, deltaY)
	}

	return t
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
