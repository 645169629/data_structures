#pragma once
using namespace std;

// ������ð������
template <typename T> void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	while (!bubble(lo, hi--));
}

// һ��ɨ�轻��
template <typename T> bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true; // ���������־
	while (++lo < hi) { // �������ң���һ����������Ԫ��
		if (_elem[lo - 1] > _elem[lo]) { // ������
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]); // ͨ������ʹ�ֲ�����
		}
	}
	return sorted;
}