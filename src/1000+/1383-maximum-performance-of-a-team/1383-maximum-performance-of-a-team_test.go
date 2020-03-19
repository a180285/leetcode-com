package src

import (
	"github.com/stretchr/testify/assert"
	"sort"
	"testing"
)

func Test1(t *testing.T) {

	// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
	// Output: 60

	assert.Equal(t, 60, maxPerformance(6, []int{2, 10, 3, 1, 5, 8}, []int{5, 4, 3, 9, 7, 2}, 2))
	assert.Equal(t, 55, maxPerformance(3, []int{2, 8, 2}, []int{2, 7, 2}, 2))

}

type Item struct {
	speed, efficiency int
}

func maxPerformance(n int, speed []int, efficiency []int, k int) int {
	items := make([]Item, n)
	for i := 0; i < n; i++ {
		items[i] = Item{speed: speed[i], efficiency: efficiency[i]}
	}

	sort.Slice(items, func(i, j int) bool {
		return items[i].speed > items[j].speed
	})

	efficiencyMap := map[int][]int{}

	for id, item := range items {
		efficiencyMap[item.efficiency] = append(efficiencyMap[item.efficiency], id)
	}

	//fmt.Printf("Speed : ")
	//for _, item := range items {
	//	fmt.Printf("%3d ", item.speed)
	//}
	//println()
	//fmt.Printf("Effic : ")
	//for _, item := range items {
	//	fmt.Printf("%3d ", item.efficiency)
	//}
	//println()

	keys := make([]int, 0, len(efficiencyMap))
	for k := range efficiencyMap {
		keys = append(keys, k)
	}

	sort.Ints(keys)

	end := k
	sumSpeed := 0

	for i := 0; i < k; i++ {
		sumSpeed += items[i].speed
	}

	performance := 0

	deleted := make([]bool, n)
	for _, efficiency := range keys {
		performance = maxInt(performance, efficiency*sumSpeed)

		for _, id := range efficiencyMap[efficiency] {
			if id < end {
				sumSpeed -= items[id].speed
				for end < n && deleted[end] {
					end++
				}
				if end != n {
					sumSpeed += items[end].speed
					end++
				}
			}
			deleted[id] = true
		}

	}

	return performance % (1e9 + 7)
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
