package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	input := []string{
		"1.3...5.9",
		"..21.94..",
		"...7.4...",
		"3..5.2..6",
		".6.....5.",
		"7..8.3..4",
		"...4.1...",
		"..92.58..",
		"8.4...1.7",
	}

	result := []string{
		"143628579",
		"572139468",
		"986754231",
		"391542786",
		"468917352",
		"725863914",
		"237481695",
		"619275843",
		"854396127",
	}

	inputBoard := stringToByte(input)

	solveSudoku(inputBoard)

	assert.Equal(t, stringToByte(result), inputBoard)
}

func solveSudoku(board [][]byte) {
	var row, column, cell [9]int
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			ch := board[i][j]
			if ch == '.' {
				continue
			}

			ch -= '0'
			row[i] |= 1 << ch
			column[j] |= 1 << ch
			cell[i/3*3+j/3] |= 1 << ch
		}
	}

	dfs(board, 0, row, column, cell)
}

func dfs(board [][]byte, idx int, row, column, cell [9]int) bool {
	if idx == 81 {
		return true
	}
	i := idx / 9
	j := idx % 9
	if board[i][j] != '.' {
		return dfs(board, idx+1, row, column, cell)
	}

	avliable := ^(row[i] | column[j] | cell[i/3*3+j/3])
	for t := 1; t <= 9; t++ {
		currentBit := 1 << (uint(t))
		if avliable&currentBit > 0 {
			row[i] ^= currentBit
			column[j] ^= currentBit
			cell[i/3*3+j/3] ^= currentBit
			board[i][j] = byte('0' + t)
			if dfs(board, idx+1, row, column, cell) {
				return true
			}
			row[i] ^= currentBit
			column[j] ^= currentBit
			cell[i/3*3+j/3] ^= currentBit
		}
	}
	board[i][j] = '.'

	return false
}

func stringToByte(strs []string) [][]byte {
	board := [][]byte{}

	for i := 0; i < 9; i++ {
		row := []byte{}
		for j := 0; j < 9; j++ {
			row = append(row, strs[i][j])
		}
		board = append(board, row)
	}

	return board
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
