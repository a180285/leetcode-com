package main__test

import (
	"github.com/stretchr/testify/assert"
	"log"
	"math"
	"testing"
)

func reverse(x int) int {
	sign := 1
	if x < 0 {
		sign = -1
		x *= -1
	}
	res := 0

	for x > 0 {
		res = res*10 + x%10
		x /= 10
	}

	res *= sign

	if res < math.MinInt32 || res > math.MaxInt32 {
		res = 0
	}

	return res
}

func TestCase1(t *testing.T) {
	log.Printf("%d %d", math.MaxInt32, math.MinInt32)
	assert.Equal(t, 321, reverse(123))
	assert.Equal(t, -321, reverse(-123))
	assert.Equal(t, -23, reverse(-320))
	assert.Equal(t, 0, reverse(1534236469))

}
