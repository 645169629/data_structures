#pragma once

// ɾ������[lo, hi)
template <typename T> int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0; // ����Ч�ʿ��ǣ����������˻����������remove(0,0)
	while (hi < _size) _elem[lo++] = _elem[hi++]; // [hi, _size) ����ǰ��hi-lo����Ԫ
	_size = lo; // ���¹�ģ��ֱ�Ӷ���β��[lo, _size=hi)����
	shrink();
	return hi - lo;
}

// ɾ����������Ϊr��Ԫ��
template <typename T> T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r+1); // ��������ɾ���㷨
	return e; // ���ر�ɾ����Ԫ��
}