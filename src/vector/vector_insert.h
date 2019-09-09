#pragma once

// 将e作为秩为r元素插入
template <typename T> Rank Vector<T>::insert(Rank r, T const& e) { // assert: 0 <= r <= size
	expand();
	for (int i = _size; i > r; i--)
		_elem[i] = _elem[i - 1]; // 自后向前，后继元素顺次向后移动一个单元
	_elem[r] = e;
	_size++;
	return r; // 返回秩
}