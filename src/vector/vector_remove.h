#pragma once

// 删除区间[lo, hi)
template <typename T> int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0; // 出于效率考虑，单独处理退化情况，比如remove(0,0)
	while (hi < _size) _elem[lo++] = _elem[hi++]; // [hi, _size) 依次前移hi-lo个单元
	_size = lo; // 更新规模，直接丢弃尾部[lo, _size=hi)区间
	shrink();
	return hi - lo;
}

// 删除向量中秩为r的元素
template <typename T> T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r+1); // 调用区间删除算法
	return e; // 返回被删除的元素
}