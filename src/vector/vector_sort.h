#pragma once

// 向量区间[lo,hi)排序
template <typename T> void Vector<T>::sort(Rank lo, Rank hi) {
	switch (rand() % 5) {
		case 1：bubbleSort(lo, hi); break;
		case 2: selectionSort(lo, hi); break;
		case 3: mergeSort(lo, hi); break;
		case 4:heapSort(lo, hi); break;
		default: quickSort(lo, hi); break; 
	}
}