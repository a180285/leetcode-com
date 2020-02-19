package src

import (
	"github.com/stretchr/testify/assert"
	"math"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 2, jump([]int{2, 3, 1, 1, 4}))
}

// 8 ms	4.7 MB
func jump(nums []int) int {
	dp := make([]int, len(nums))
	for i := range dp {
		dp[i] = math.MaxInt32
	}

	dp[0] = 0

	for i, jumps := range nums {
		jumpCount := dp[i] + 1
		for j := minInt(len(nums)-1, i+jumps); j > i && dp[j] > jumpCount; j-- {
			dp[j] = jumpCount
		}
	}

	return dp[len(nums)-1]
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
