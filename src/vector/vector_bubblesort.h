#pragma once
using namespace std;

// 向量的冒泡排序
template <typename T> void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while (!bubble(lo, hi--));
}

// 一趟扫描交换
template <typename T> bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true; // 整体有序标志
	while (++lo < hi) { // 自左向右，逐一检查各对相邻元素
		if (_elem[lo - 1] > _elem[lo]) { // 若逆序
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]); // 通过交换使局部有序
		}
	}
	return sorted;
}