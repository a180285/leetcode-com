package _12

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, "III", intToRoman(3))
	assert.Equal(t, "IV", intToRoman(4))
	assert.Equal(t, "IX", intToRoman(9))
	assert.Equal(t, "LVIII", intToRoman(58))
	assert.Equal(t, "MCMXCIV", intToRoman(1994))

}

// Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000

func intToRoman(num int) string {
	str := ""

	for ; num >= 1000; num -= 1000 {
		str += "M"
	}

	str += _intToRoman(num, 100, "C", "D", "M") +
		_intToRoman(num, 10, "X", "L", "C") +
		_intToRoman(num, 1, "I", "V", "X")
	return str
}

func _intToRoman(n int, unit int, I, V, X string) string {
	str := ""
	n %= unit * 10
	n /= unit

	switch n {
	case 9:
		str = I + X
	case 4:
		str = I + V
	default:
		if n >= 5 {
			str += V
			n -= 5
		}
		for ; n > 0; n-- {
			str += I
		}
	}

	return str
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
