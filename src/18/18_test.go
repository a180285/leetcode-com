package src

import (
	"github.com/stretchr/testify/assert"
	"sort"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, [][]int{{0, 0, 0, 0}}, fourSum([]int{0, 0, 0, 0, 0}, 0))
	assert.Equal(t, [][]int{
		{-1, 0, 0, 1},
		{-2, -1, 1, 2},
		{-2, 0, 0, 2},
	}, fourSum([]int{1, 0, -1, 0, -2, 2}, 0))
}

func fourSum(nums []int, target int) [][]int {
	results := [][]int{}
	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {
		vi := nums[i]
		if vi*4 > target {
			break
		}

		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < len(nums); j++ {
			vj := nums[j]
			if vi+vj*3 > target {
				break
			}

			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}

			for k := j + 1; k < len(nums); k++ {
				vk := nums[k]
				sum := vi + vj + vk
				if sum+vk > target {
					break
				}

				if k > j+1 && nums[k] == nums[k-1] {
					continue
				}

				newsList := nums[k+1:]
				findNum := target - sum
				idx := sort.SearchInts(newsList, findNum)
				if idx < len(newsList) && newsList[idx] == findNum {
					results = append(results, []int{vi, vj, vk, newsList[idx]})
				}
			} // k
		} // j
	} // i

	return results
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
