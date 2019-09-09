#pragma once

// ��e��Ϊ��ΪrԪ�ز���
template <typename T> Rank Vector<T>::insert(Rank r, T const& e) { // assert: 0 <= r <= size
	expand();
	for (int i = _size; i > r; i--)
		_elem[i] = _elem[i - 1]; // �Ժ���ǰ�����Ԫ��˳������ƶ�һ����Ԫ
	_elem[r] = e;
	_size++;
	return r; // ������
}