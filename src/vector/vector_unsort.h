#pragma once

using namespace std;

template <typename T> void Vector<T>::unsort(Rank lo, Rank hi) { // 等概率随机置乱区间[lo, hi)
	T* V = _elem + lo; // 将子向量_elem[lo, hi)视作另一向量V[0, hi-lo)
	for (Rank i = hi - lo; i > 0; i--)
		swap(V[i - 1], V[rand() % i]);
}