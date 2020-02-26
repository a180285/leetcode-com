package src

import (
	"github.com/stretchr/testify/assert"
	"sort"
	"strings"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, "981", largestMultipleOfThree([]int{8, 1, 9}))
	assert.Equal(t, "8760", largestMultipleOfThree([]int{8, 6, 7, 1, 0}))
	assert.Equal(t, "0", largestMultipleOfThree([]int{0, 0, 0, 0}))
	assert.Equal(t, "", largestMultipleOfThree([]int{1}))
	assert.Equal(t, "2211", largestMultipleOfThree([]int{2, 2, 1, 1, 1}))
	assert.Equal(t, "111", largestMultipleOfThree([]int{2, 1, 1, 1}))
}

func largestMultipleOfThree(digits []int) string {
	dp := make([][]int, 3)
	for i := 0; i < 3; i++ {
		dp[i] = []int{}
	}

	for _, digit := range digits {
		idx := digit % 3
		dp[idx] = append(dp[idx], digit)
	}

	for i := 0; i < 3; i++ {
		sort.Sort(sort.Reverse(sort.IntSlice(dp[i])))
	}

	newDp := copyDp(dp)
	str1 := getDigitsForUse1(newDp)

	newDp = copyDp(dp)
	str2 := getDigitsForUse2(newDp)

	if len(str1) > len(str2) {
		return str1
	} else if len(str1) == len(str2) && str1 > str2 {
		return str1
	} else {
		return str2
	}
}

func copyDp(dp [][]int) [][]int {
	return [][]int{
		dp[0],
		dp[1],
		dp[2],
	}
}

func getDigitsForUse2(dp [][]int) string {
	digitsForUse := []int{}
	digitsForUse = append(digitsForUse, dp[0]...)

	minLength := minInt(len(dp[1]), len(dp[2]))
	digitsForUse = append(digitsForUse, dp[1][:minLength]...)
	digitsForUse = append(digitsForUse, dp[2][:minLength]...)
	dp[1] = dp[1][minLength:]
	dp[2] = dp[2][minLength:]

	for i := 1; i < 3; i++ {
		cutCount := len(dp[i]) / 3 * 3
		digitsForUse = append(digitsForUse, dp[i][:cutCount]...)

		dp[i] = dp[i][cutCount:]
	}

	sort.Sort(sort.Reverse(sort.IntSlice(digitsForUse)))

	if len(digitsForUse) == 0 {
		return ""
	}

	if digitsForUse[0] == 0 {
		return "0"
	}

	sb := strings.Builder{}

	for _, digit := range digitsForUse {
		sb.WriteRune(rune(digit + '0'))
	}

	return sb.String()
}

func getDigitsForUse1(dp [][]int) string {
	digitsForUse := []int{}
	digitsForUse = append(digitsForUse, dp[0]...)

	for i := 1; i < 3; i++ {
		cutCount := len(dp[i]) / 3 * 3
		digitsForUse = append(digitsForUse, dp[i][:cutCount]...)

		dp[i] = dp[i][cutCount:]
	}

	minLength := minInt(len(dp[1]), len(dp[2]))
	digitsForUse = append(digitsForUse, dp[1][:minLength]...)
	digitsForUse = append(digitsForUse, dp[2][:minLength]...)
	dp[1] = dp[1][minLength:]
	dp[2] = dp[2][minLength:]

	sort.Sort(sort.Reverse(sort.IntSlice(digitsForUse)))

	if len(digitsForUse) == 0 {
		return ""
	}

	if digitsForUse[0] == 0 {
		return "0"
	}

	sb := strings.Builder{}

	for _, digit := range digitsForUse {
		sb.WriteRune(rune(digit + '0'))
	}

	return sb.String()
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
