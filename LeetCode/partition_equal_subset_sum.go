package main

import "math/bits"

// self implemented bitset
type BitSet struct {
	size int
	c    []uint64
}

func NewBitSet(n int) BitSet {
	return BitSet{
		size: n/64 + 1,
		c:    make([]uint64, n/64+1),
	}
}

func (bs *BitSet) Get(index int) bool {
	val := bs.c[index/64] & (uint64(1) << uint64(index%64))
	return val > 0
}

func (bs *BitSet) Set(index int) {
	bs.c[index/64] |= (uint64(1) << uint64(index%64))
}

func (bs *BitSet) Count() int {
	ans := 0
	for i := 0; i < bs.size; i++ {
		ans += bits.OnesCount64(bs.c[i])
	}
	return ans
}

func (bs *BitSet) And(a BitSet) {
	for i := 0; i < bs.size; i++ {
		bs.c[i] &= a.c[i]
	}
}

func (bs *BitSet) Or(a BitSet) {
	for i := 0; i < bs.size; i++ {
		bs.c[i] |= a.c[i]
	}
}

func (bs *BitSet) ShiftLeft(num int) {
	for k := 0; k < num; k++ {
		for i := bs.size - 1; i >= 0; i-- {
			bs.c[i] <<= 1
			if i > 0 {
				bs.c[i] |= bs.c[i-1] >> 63
			}
		}
	}
}

func (bs *BitSet) ShiftRight(num int) {
	for k := 0; k < num; k++ {
		for i := 0; i < bs.size; i++ {
			bs.c[i] >>= 1
			if i < bs.size-1 {
				bs.c[i] |= (bs.c[i+1] & 1) << 63
			}
		}
	}
}

func AndCount(a, b BitSet) int {
	if a.size != b.size {
		return 0
	}

	ans := 0
	for i := 0; i < a.size; i++ {
		ans += bits.OnesCount64(a.c[i] & b.c[i])
	}
	return ans
}

func OrCount(a, b BitSet) int {
	if a.size != b.size {
		return 0
	}

	ans := 0
	for i := 0; i < a.size; i++ {
		ans += bits.OnesCount64(a.c[i] | b.c[i])
	}
	return ans
}

func canPartition(nums []int) bool {
	sum := 0

	bs := NewBitSet(20005)
	bs.Set(0)

	for _, num := range nums {
		sum += num

		previousBs := NewBitSet(20005)
		previousBs.Or(bs)
		previousBs.ShiftLeft(num)

		bs.Or(previousBs)
	}

	return (sum&1) == 0 && bs.Get(sum/2)
}
