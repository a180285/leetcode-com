package src

import (
	"github.com/stretchr/testify/assert"
	"math"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, []int{3, 3}, closestDivisors(8))
	assert.Equal(t, []int{2, 1}, closestDivisors(1))
	assert.Equal(t, []int{25, 40}, closestDivisors(999))
}

func closestDivisors(num int) []int {
	s1 := _closestDivisors(num + 1)
	s2 := _closestDivisors(num + 2)
	if absInt(s1[0]-s1[1]) < absInt(s2[0]-s2[1]) {
		return s1
	} else {
		return s2
	}
}

func _closestDivisors(num int) []int {
	sqr := int(math.Sqrt(float64(num)))
	for sqr*sqr < num {
		sqr++
	}

	for v := sqr; ; v-- {
		if num%v == 0 {
			return []int{v, num / v}
		}
	}
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
