package __ZigZag_Conversion__test

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
func TestCase1(t *testing.T) {
	assert.Equal(t, "PAHNAPLSIIGYIR", convert("PAYPALISHIRING", 3))
}

//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
func TestCase2(t *testing.T) {
	assert.Equal(t, "PINALSIGYAHRPI", convert("PAYPALISHIRING", 4))
}

func TestCase3(t *testing.T) {
	assert.Equal(t, "ACBD", convert("ABCD", 2))
	assert.Equal(t, "ABCD", convert("ABCD", 1))
}

func convert(s string, numRows int) string {
	if numRows < 2 {
		return s
	}

	runeString := []rune(s)
	length := len(s)

	r := numRows
	c := length/(numRows-1) + 10

	matrix := make([][]int, r)
	for i := 0; i < r; i++ {
		matrix[i] = make([]int, c)
	}

	cid := -1
	for i := 0; i < length; i += 2*r - 2 {
		cid++
		for j := 0; i+j < length && j < r; j++ {
			matrix[j][cid] = int(runeString[i+j])
		}
		cid++
		for j := 0; i+r+j < length && j < r-2; j++ {
			matrix[r-2-j][cid] = int(runeString[i+r+j])
		}
	}

	runeRes := []rune{}
	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if matrix[i][j] != 0 {
				fmt.Printf("%c", matrix[i][j])
				runeRes = append(runeRes, rune(matrix[i][j]))
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Println("")
	}

	return string(runeRes)
}
