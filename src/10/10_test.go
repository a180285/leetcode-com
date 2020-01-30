package _10

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, false, isMatch("aa", "a"))
	assert.Equal(t, true, isMatch("aa", "a*"))
	assert.Equal(t, true, isMatch("ab", ".*"))
	assert.Equal(t, true, isMatch("aab", "c*a*b"))
	assert.Equal(t, false, isMatch("mississippi", "mis*is*p*."))
	assert.Equal(t, true, isMatch("mississippi", ".*s.*"))
	assert.Equal(t, true, isMatch("a", "a.*"))
}

func isMatch(s string, p string) bool {
	return _isMatch(s, p, 0, 0)
}

func _isMatch(s, p string, si, pi int) bool {
	if si == len(s) && pi == len(p) {
		return true
	}

	if pi+1 < len(p) && p[pi+1] == '*' {
		if _isMatch(s, p, si, pi+2) {
			return true
		}
		for si < len(s) {
			if s[si] == p[pi] || p[pi] == '.' {
				if _isMatch(s, p, si+1, pi+2) {
					return true
				}
				si++
			} else {
				break
			}
		}
		return false
	}

	if si == len(s) || pi == len(p) {
		return false
	}

	if s[si] == p[pi] || p[pi] == '.' {
		return _isMatch(s, p, si+1, pi+1)
	}

	return false
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
