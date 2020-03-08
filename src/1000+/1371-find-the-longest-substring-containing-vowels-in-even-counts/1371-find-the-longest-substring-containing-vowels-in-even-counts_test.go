package src

import (
	"github.com/stretchr/testify/assert"
	"math"
	"strings"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 13, findTheLongestSubstring("eleetminicoworoep"))
}

func findTheLongestSubstring(s string) int {
	vowel := "aeiou"

	dp := make([]int, 1<<uint8(len(vowel)))

	for i := range dp {
		dp[i] = math.MaxInt32
	}

	lastDp := 0
	dp[0] = -1

	maxLength := 0

	for i := 0; i < len(s); i++ {
		vid := strings.IndexByte(vowel, s[i])
		if vid != -1 {
			nowDp := lastDp ^ (1 << uint8(vid))
			if dp[nowDp] > i {
				dp[nowDp] = i
			}
			lastDp = nowDp
		}
		maxLength = maxInt(maxLength, i-dp[lastDp])
	}

	return maxLength
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
