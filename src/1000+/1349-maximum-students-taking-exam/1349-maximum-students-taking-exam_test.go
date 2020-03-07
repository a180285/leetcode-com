package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	input := [][]byte{
		[]byte("#...#"),
		[]byte(".#.#."),
		[]byte("..#.."),
		[]byte(".#.#."),
		[]byte("#...#"),
	}

	assert.Equal(t, 10, maxStudents(input))
}

func maxStudents(seats [][]byte) int {
	rows := len(seats)
	columns := len(seats[0])

	seatsBit := []int{}
	for _, row := range seats {
		seatBit := 0
		for idx, seat := range row {
			if seat == '.' {
				seatBit |= 1 << uint8(idx)
			}
		}
		seatsBit = append(seatsBit, seatBit)
	}
	upRow := [256]int{}
	nowRow := [256]int{}

	maxBits := (1 << uint8(columns))
	for rowId := 0; rowId < rows; rowId++ {
		for nowBits := 0; nowBits < maxBits; nowBits++ {
			if seatsBit[rowId]&nowBits != nowBits {
				continue
			}
			count := checkRowBits(nowBits)
			if count < 0 {
				continue
			}
			for upBits := 0; upBits < maxBits; upBits++ {
				if upBits&(nowBits>>1) != 0 {
					continue
				} else if upBits&(nowBits<<1) != 0 {
					continue
				}
				nowRow[nowBits] = maxInt(nowRow[nowBits], upRow[upBits]+count)
			}
		}

		upRow = nowRow
		nowRow = [256]int{}
	}

	maxCount := 0
	for _, count := range upRow {
		maxCount = maxInt(maxCount, count)
	}

	return maxCount
}

func checkRowBits(bits int) int {
	if bits&(bits<<1) != 0 {
		return -1
	} else if bits&(bits>>1) != 0 {
		return -1
	}

	count := 0
	for bits > 0 {
		bits &= bits - 1
		count++
	}
	return count
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
