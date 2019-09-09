#pragma once

template <typename T> int Vector<T>::disordered() const { // 返回向量中逆序相邻元素对的总数
	int n = 0; // 计数器
	for (int i = 1; i < _size; i++) {
		// 逐一检查_size-1对相邻元素，逆序则计数
		if (_elem[i - 1] > _elem[i]) n++;
	}
	return n; // 向量有序当且仅当 n=0
}