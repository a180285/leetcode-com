package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, []int{0, 9}, findSubstring("barfoothefoobarman", []string{"foo", "bar"}))
	assert.Equal(t, []int{}, findSubstring("wordgoodgoodgoodbestword", []string{"word", "good", "best", "word"}))
	assert.Equal(t, []int{8}, findSubstring("wordgoodgoodgoodbestword", []string{"word", "good", "best", "good"}))
	assert.Equal(t, []int{0, 2, 1}, findSubstring("aaaaaaaa", []string{"aa", "aa", "aa"}))
}

func findSubstring(s string, words []string) []int {
	indexes := []int{}
	if len(s) == 0 || len(words) == 0 || len(words[0]) == 0 {
		return indexes
	}

	wordLength := len(words[0])
	wordCountMap := map[string]int{}
	for _, word := range words {
		wordCountMap[word]++
	}

	mapToCopy := copyMap(wordCountMap)

	for i := 0; i < wordLength; i++ {
		if i+len(words)*wordLength > len(s) {
			break
		}

		wordCountMap := copyMap(mapToCopy)

		foundCount := 0
		for j := 0; j < len(words); j++ {
			wordStart := i + j*wordLength
			word := s[wordStart : wordStart+wordLength]
			if nowCount, ok := wordCountMap[word]; ok {
				if nowCount > 0 {
					foundCount++
				}
				wordCountMap[word] = nowCount - 1
			}
		}
		if foundCount == len(words) {
			indexes = append(indexes, i)
		}
		for j := len(words); i+(j+1)*wordLength <= len(s); j++ {
			newWordStart := i + j*wordLength
			newWord := s[newWordStart : newWordStart+wordLength]

			oldWordStart := i + (j-len(words))*wordLength
			oldWord := s[oldWordStart : oldWordStart+wordLength]

			if nowCount, ok := wordCountMap[oldWord]; ok {
				if nowCount >= 0 {
					foundCount--
				}
				wordCountMap[oldWord] = nowCount + 1
			}

			if nowCount, ok := wordCountMap[newWord]; ok {
				if nowCount > 0 {
					foundCount++
				}
				wordCountMap[newWord] = nowCount - 1
			}

			if foundCount == len(words) {
				indexes = append(indexes, i+(j-len(words)+1)*wordLength)
			}
		}
	}

	return indexes
}

func copyMap(orgMap map[string]int) map[string]int {
	newMap := make(map[string]int, len(orgMap))
	for k, v := range orgMap {
		newMap[k] = v
	}
	return newMap
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
