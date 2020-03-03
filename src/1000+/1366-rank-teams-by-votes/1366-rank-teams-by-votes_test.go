package src

import (
	"github.com/stretchr/testify/assert"
	"sort"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, "ACB", rankTeams([]string{"ABC", "ACB", "ABC", "ACB", "ACB"}))
	assert.Equal(t, "ABC", rankTeams([]string{"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"}))

}

type Vote struct {
	rankCount [26]int
	char      int
	hasVale   bool
}

type VoteList []Vote

func (a VoteList) Len() int      { return len(a) }
func (a VoteList) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a VoteList) Less(i, j int) bool {
	va, vb := a[i], a[j]

	if va.hasVale != vb.hasVale {
		return va.hasVale
	}

	for id := range va.rankCount {
		if va.rankCount[id] != vb.rankCount[id] {
			return va.rankCount[id] > vb.rankCount[id]
		}
	}

	return va.char < vb.char
}

func rankTeams(votes []string) string {
	voteList := make([]Vote, 26)

	for i := 0; i < len(votes); i++ {
		voteStr := votes[i]
		for j := 0; j < len(voteStr); j++ {
			vote := voteStr[j] - 'A'
			voteList[vote].rankCount[j]++
			voteList[vote].char = int(vote)
			voteList[vote].hasVale = true
		}
	}

	sort.Sort(VoteList(voteList))

	s := ""
	for i := 0; i < len(voteList); i++ {
		if !voteList[i].hasVale {
			break
		}
		s += string('A' + voteList[i].char)
	}

	return s
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
