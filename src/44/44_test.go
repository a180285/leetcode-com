package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, false, isMatch("aa", "a"))
	assert.Equal(t, true, isMatch("aa", "*"))
	assert.Equal(t, true, isMatch("adceb", "*a*b"))
	assert.Equal(t, true, isMatch("adceb", "*a*?*b"))
	assert.Equal(t, false, isMatch("bbbababbbbabbbbababbaaabbaababbbaabbbaaaabbbaaaabb", "*b********bb*b*bbbbb*ba"))
}

func isMatch(s string, p string) bool {
	s = "_" + s + "_"
	p = "_" + p + "_"

	dp := make2DInt(len(s), len(p))
	dp[0][0] = 1
	for i := 0; i < len(s); i++ {
		for j := 0; j < len(p); j++ {
			if p[j] == '*' {
				if i > 0 && dp[i-1][j] == 1 {
					dp[i][j] = 1
				} else if j > 0 && dp[i][j-1] == 1 {
					dp[i][j] = 1
				} else if i > 0 && j > 0 {
					dp[i][j] = dp[i-1][j-1]
				}
			} else if i > 0 && j > 0 && (p[j] == '?' || s[i] == p[j]) {
				dp[i][j] = dp[i-1][j-1]
			}
		}
	}

	//fmt.Printf(" -> %s\n", p)
	//for i := 0; i < len(s); i++ {
	//	fmt.Printf("%c - ", s[i])
	//	for j := 0; j < len(p); j++ {
	//		fmt.Printf("%d", dp[i][j])
	//	}
	//	fmt.Println()
	//}
	//fmt.Println()

	return dp[len(s)-1][len(p)-1] == 1
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
