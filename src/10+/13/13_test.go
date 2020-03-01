package _13

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 3, romanToInt("III"))
	assert.Equal(t, 4, romanToInt("IV"))
	assert.Equal(t, 9, romanToInt("IX"))
	assert.Equal(t, 58, romanToInt("LVIII"))
	assert.Equal(t, 1994, romanToInt("MCMXCIV"))

}

// Symbol       Value

var symbolMap = map[string]int{
	"I": 1,
	"V": 5,
	"X": 10,
	"L": 50,
	"C": 100,
	"D": 500,
	"M": 1000,
}

func romanToInt(s string) int {
	result := 0
	for i := 0; i < len(s); i++ {
		ch := s[i : i+1]
		value := symbolMap[ch]
		if i+1 < len(s) && symbolMap[s[i+1:i+2]] > symbolMap[ch] {
			result -= value
		} else {
			result += value
		}
	}
	return result
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
