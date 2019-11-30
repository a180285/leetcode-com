package _269

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {
	assert.Equal(t, 4, numWays(3, 2))
	assert.Equal(t, 2, numWays(2, 4))
	assert.Equal(t, 8, numWays(4, 2))
	assert.Equal(t, 127784505, numWays(27, 7))
}

func numWays(steps int, arrLen int) int {
	arrLen = minInt(arrLen, steps/2+1)
	mod := int(1e9 + 7)
	//log.Printf("mod: %d", mod)
	dp := make2DInt(steps+10, arrLen+10)

	for i := 0; i <= arrLen; i++ {
		dp[1][i] = 1
		dp[0][i] = 1
	}

	for step := 1; step <= steps; step++ {
		dp[step][1] = 1
		dp[step][0] = 1
		for l := 2; l <= arrLen; l++ {
			count := dp[step-1][l]

			for k := 0; k <= step-2; k++ {
				now := dp[k][l-1] * dp[step-2-k][l] % mod
				count = (count + now) % mod
			}

			dp[step][l] = count
		}
	}

	return dp[steps][arrLen]
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
