package _268

import "sort"

func suggestedProducts(products []string, searchWord string) [][]string {
	sort.Strings(products)
	sn := len(products)

	res := [][]string{}
	search := ""
	for i := 0; i < len(searchWord); i++ {
		search += searchWord[i : i+1]

		idx := sort.SearchStrings(products, search)
		suggest := []string{}
		for j := 0; idx+j < sn && j < 3; j++ {
			if len(products[idx+j]) < i+1 || search != products[idx+j][:i+1] {
				break
			}
			suggest = append(suggest, products[idx+j])
		}

		res = append(res, suggest)
	}

	return res
}
