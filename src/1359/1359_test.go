package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 1, countOrders(1))
	assert.Equal(t, 6, countOrders(2))
	assert.Equal(t, 90, countOrders(3))
}

const MOD = int(1e9 + 7)

func countOrders(n int) int {
	ans := 0

	dp := make([]int, n+10)

	dp[1] = 1
	for i := 2; i <= n; i++ {
		dp[i] = (2*i - 1) * dp[i-1]
		dp[i] %= MOD
	}

	ans = dp[n] * factorial(n)

	return ans % MOD
}

func factorial(n int) int {
	ans := 1
	for i := 2; i <= n; i++ {
		ans = (ans * i) % MOD
	}
	return ans
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
