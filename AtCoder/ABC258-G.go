package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
)

// stdin reader & stdout writer
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

// self implemented bitset
type BitSet struct {
	size int
	c    []uint64
}

func NewBitSet(n int) BitSet {
	return BitSet{
		size: n,
		c:    make([]uint64, n/64+1),
	}
}

func (bs *BitSet) Set(index int) {
	bs.c[index/64] |= (uint64(1) << uint64(index%64))
}

func AndCount(a, b BitSet) int {
	n := len(a.c)
	ans := 0
	for i := 0; i < n; i++ {
		ans += bits.OnesCount64(a.c[i] & b.c[i])
	}
	return ans
}

func main() {
	defer writer.Flush()

	var n int
	var grid [3003][3003]int
	var bs [3003]BitSet

	scanf("%d", &n)
	reader.ReadString('\n')

	for i := 0; i < n; i++ {
		bs[i] = NewBitSet(n)
		for j := 0; j < n; j++ {
			scanf("%c", &grid[i][j])
			if grid[i][j] == '1' {
				bs[i].Set(j)
			}
		}
		reader.ReadString('\n')
	}

	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if grid[i][j] == '1' {
				ans += AndCount(bs[i], bs[j])
			}
		}
	}

	printf("%d\n", ans/3)
}
