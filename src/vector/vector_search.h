#pragma once
#include "../fibonacci/fib.h"

// 在有序向量的区间[lo,hi)内，确定不大于e的最后一个节点的秩
template <typename T> Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
	// 以50%的概率随机使用二分查找或Fibonacci查找
	return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(-elem, e, lo, hi);
}

// Fibonacci查找算法（版本A）：在有序向量的区间[lo,hi)内查找元素e，0 <= lo <= hi <= _size
template <typename T> static Rank fibSearch(T * A, T const& e, Rank lo, Rank hi) {
	Fib fib(hi - lo); // 用O(log_phi(n = hi - lo)时间创建Fib数列)
	while (lo < hi) { // 每步迭代可能要做两次比较判断，有三个分支
		while (hi - lo < fib.get()) fib.prev(); // 通过向前顺序查找（分摊O(1)）
		Rank mi = lo + fib.get() - 1; // 确定形如Fib(k) - 1的轴点
		if (e < A[mi]) hi = mi; // 深入前半段[lo,hi)继续查找
		else if (A[mi] < e) lo = mi + 1; // 深入后半段（mi, hi）继续查找
		else return mi; // 在mi处命中
	} // 成功查找可以提前终止
	return -1; // 查找失败
} // 有多个命中元素时，不能保证返回秩最大者；失败时，简单的返回-1，而不能指示失败的位置

// 二分查找算法（版本A）：在有序向量的区间[lo,hi)内查找元素e
template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
	while (lo < hi) { // 每步迭代可能要做两次比较判断，有三个分支
		Rank mi = (lo + hi) >> 1; // 以中点为轴点
		if (e < A[mi]) hi = mi; // 深入前半段[lo,hi)继续查找
		else if (A[mi] < e) lo = mi + 1; // 深入后半段(mi,hi)继续查找
		else return mi; // 在mi处命中
	}
	return -1; // 查找失败
} // 有多个命中元素时，不能保证返回秩最大者；查找失败时，简单的返回-1，而不能指示失败的位置

// 二分查找算法（版本B）：在有序向量的区间[lo,hi)内查找元素e， 0 <= lo <= hi <= _size
template<typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
	while (1 < hi - lo) { // 每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
		Rank mi = (lo + hi) >> 1; // 以中点为轴点
		（e < A[mi]） ? hi = mi : lo = mi; // 经比较后确定深入[lo, hi)或[mi, hi)
	}// 出口时hi = lo +1，查找区间仅含一个元素A[lo]
	return (e == A[lo]) ? lo : -1; // 查找成功时返回对应的秩；否则统一返回-1
} // 有多个命中元素时，不能保证返回秩最大者；查找失败时，简单返回-1，而不能指示失败的位置

// 二分查找算法（版本C）：在有序向量的区间[lo,hi)内查找元素e, 0 <= lo <= hi <= _size
template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1; // 经比较后确定深入[lo,mi) 或 (mi,hi)
	} // 成功查找不能提前终止
	return --lo; //循环结束时，lo为大于e的元素的最小秩，故lo-1即不大于e的最大秩
} //有多个命中元素时，总能保证返回秩最大者；查找失败时，能够返回失败的位置 

