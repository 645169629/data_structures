#pragma once

// ɾ�������������ظ�Ԫ��
template <typename T> int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1; // ��_elem[1]��ʼ
	while (i < _size) // ��ǰ�����һ�����Ԫ��_elem[i]
		find(_elem[i], 0, i) < 0  ? i++ : remove(i); // ��ǰ׺��Ѱ����֮��ͬ�ߣ�������ͬ����������̣�����ɾ����ͬ��
	return oldSize - _size;
}