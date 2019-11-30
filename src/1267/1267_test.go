package _267

import "testing"

func Test1(t *testing.T) {
}

func countServers(grid [][]int) int {
	res := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				connected := 0
				for k := 0; k < len(grid); k++ {
					if k == i {
						continue
					}
					if grid[k][j] == 1 {
						connected = 1
					}
				}
				for k := 0; k < len(grid[0]); k++ {
					if k == j {
						continue
					}
					if grid[i][k] == 1 {
						connected = 1
					}
				}

				res += connected
			}
		}
	}

	return res
}
