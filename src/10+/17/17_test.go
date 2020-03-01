package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}, letterCombinations("23"))
}

func letterCombinations(digits string) []string {
	if digits == "" {
		return []string{}
	}
	keysInLetter := []string{
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz",
	}
	words := []string{}

	return _letterCombinations(digits, "", keysInLetter, &words)
}

func _letterCombinations(digits string, now string, keysInLetter []string, words *[]string) []string {
	if len(digits) == 0 {
		*words = append(*words, now)
		return *words
	}

	ch := digits[0] - '0'
	for _, letter := range keysInLetter[ch] {
		_letterCombinations(digits[1:], now+string(letter), keysInLetter, words)
	}

	return *words
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
