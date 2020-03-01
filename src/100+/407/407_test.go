package src

import (
	"container/heap"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 4, trapRainWater([][]int{
		{1, 4, 3, 1, 3, 2},
		{3, 2, 1, 3, 2, 4},
		{2, 3, 3, 2, 3, 1},
	}))
}

type HeightIndexNode struct {
	x, y   int
	height int
}

type HeightIndexHeap []HeightIndexNode

func (h HeightIndexHeap) Len() int           { return len(h) }
func (h HeightIndexHeap) Less(i, j int) bool { return h[i].height < h[j].height }
func (h HeightIndexHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *HeightIndexHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(HeightIndexNode))
}

func (h *HeightIndexHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func trapRainWater(heightMap [][]int) int {

	if len(heightMap) == 0 || len(heightMap[0]) == 0 {
		return 0
	}

	rows := len(heightMap)
	columns := len(heightMap[0])

	used := [][]bool{}
	for _ = range heightMap {
		tmp := make([]bool, len(heightMap[0]))
		used = append(used, tmp)
	}

	heightHeap := &HeightIndexHeap{}

	for x := 0; x < rows; x++ {
		heightHeap.Push(HeightIndexNode{x, 0, heightMap[x][0]})
		heightHeap.Push(HeightIndexNode{x, columns - 1, heightMap[x][columns-1]})
		used[x][0] = true
		used[x][columns-1] = true
	}

	for y := columns - 2; y > 0; y-- {
		heightHeap.Push(HeightIndexNode{0, y, heightMap[0][y]})
		heightHeap.Push(HeightIndexNode{rows - 1, y, heightMap[rows-1][y]})
		used[0][y] = true
		used[rows-1][y] = true
	}

	//fmt.Printf("%+v\n", used)
	//fmt.Printf("%+v\n", heightHeap)

	heap.Init(heightHeap)

	//fmt.Printf("%+v\n", heightHeap)

	currentHeight := 0
	water := 0

	dx := []int{0, 0, -1, 1}
	dy := []int{-1, 1, 0, 0}

	for heightHeap.Len() > 0 {
		node := heap.Pop(heightHeap).(HeightIndexNode)
		//fmt.Printf("%+v\n", node)
		if currentHeight > node.height {
			water += currentHeight - node.height
		} else {
			currentHeight = node.height
		}

		for i := 0; i < 4; i++ {
			tx := node.x + dx[i]
			ty := node.y + dy[i]
			if inRange(tx, 0, rows) && inRange(ty, 0, columns) && !used[tx][ty] {
				heap.Push(heightHeap, HeightIndexNode{tx, ty, heightMap[tx][ty]})
				used[tx][ty] = true
			}
		}
	}

	return water
}

func inRange(x, low, high int) bool {
	return x >= low && x < high
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
