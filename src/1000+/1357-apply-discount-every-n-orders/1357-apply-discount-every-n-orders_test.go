package src

import (
	"testing"
)

func Test1(t *testing.T) {

	//	cashier := Constructor(3, 50,
	//		[]int{1, 2, 3, 4, 5, 6, 7},
	//		[]int{100, 200, 300, 400, 300, 200, 100})
	//
	//[[1,2],[1,2]],
	//[[3,7],[10,10]],
	//[[1,2,3,4,5,6,7],[1,1,1,1,1,1,1]],
	//[[4],[10]],
	//[[7,3],[10,10]],
	//[[7,5,3,1,6,4,2],[10,10,10,9,9,9,7]],
	//[[2,3,5],[5,3,2]]]

	//assert.Equal(t, math.MaxInt32, cashier.GetBill())
}

type Cashier struct {
	n        int
	discount int
	products []int
	prices   []int

	customerCount int
}

func Constructor(n int, discount int, products []int, prices []int) Cashier {
	return Cashier{
		n:        n,
		discount: discount,
		products: products,
		prices:   prices,
	}
}

func (this *Cashier) GetBill(product []int, amount []int) float64 {
	cost := int64(0)
	for pindex, pid := range product {
		for idx := range this.products {
			if pid == this.products[idx] {
				cost += int64(this.prices[idx] * amount[pindex])
			}
		}
	}

	this.customerCount++
	if this.customerCount == this.n {
		this.customerCount = 0
		return float64(cost) * (1 - float64(this.discount)/100)
	} else {
		return float64(cost)
	}
}

/**
 * Your Cashier object will be instantiated and called as such:
 * obj := Constructor(n, discount, products, prices);
 * param_1 := obj.GetBill(product,amount);
 */

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
