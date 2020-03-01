package src

import (
	"container/heap"
	"github.com/stretchr/testify/assert"
	"math"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 3, minCost([][]int{
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{1, 1, 1, 1},
		{2, 2, 2, 2},
	}))
}

type GridCost struct {
	x, y int
	cost int
}

// An IntHeap is a min-heap of ints.
type CostHeap []GridCost

func (h CostHeap) Len() int           { return len(h) }
func (h CostHeap) Less(i, j int) bool { return h[i].cost < h[j].cost }
func (h CostHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *CostHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(GridCost))
}

func (h *CostHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

var dx = []int{0, 0, 0, 1, -1}
var dy = []int{0, 1, -1, 0, 0}

func minCost(grid [][]int) int {
	r := len(grid)
	c := len(grid[0])
	costs := make2DInt(r, c)
	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			costs[i][j] = math.MaxInt32
		}
	}

	costs[0][0] = 0
	costHeap := &CostHeap{}
	heap.Init(costHeap)

	heap.Push(costHeap, GridCost{0, 0, 0})
	for costHeap.Len() > 0 {
		cost := heap.Pop(costHeap).(GridCost)

		dr := grid[cost.x][cost.y]
		tx := cost.x + dx[dr]
		ty := cost.y + dy[dr]
		if inRange(tx, 0, r) && inRange(ty, 0, c) {
			if costs[tx][ty] > cost.cost {
				costs[tx][ty] = cost.cost
				heap.Push(costHeap, GridCost{tx, ty, costs[tx][ty]})
			}
		}

		newCost := cost.cost + 1
		for dr = 1; dr <= 4; dr++ {
			tx = cost.x + dx[dr]
			ty = cost.y + dy[dr]
			if inRange(tx, 0, r) && inRange(ty, 0, c) {
				if costs[tx][ty] > newCost {
					costs[tx][ty] = newCost
					heap.Push(costHeap, GridCost{tx, ty, costs[tx][ty]})
				}
			}
		}
	}
	return costs[r-1][c-1]
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
