#pragma once


// ÿ��ѭ������Ҫִ��remove�Ļ���ʱ�临�Ӷ�Ϊ (n-2)+(n-3)+...+2+1 = O(n^2)
//template <typename T> int Vector<T>::uniquify() { // ���������ظ�Ԫ���޳��㷨����Ч�棩
//	int oldSize = _size; int i = 1;
//	while (i < _size)
//		// ��ǰ�����һ�ȶԸ�����Ԫ�أ�����ͬ��ɾ�����ߣ�����ת����һԪ��
//		_elem[i - 1] == _elem[i] ? remove(i) : i++;
//	return oldSize - _size;
//}

// ʱ�临�Ӷ�ΪO(n)
template <typename T> int Vector<T>::uniquify() { // ���������ظ�Ԫ���޳��㷨����Ч�棩
	Rank i = 0, j = 0; // ���Ի��조���ڡ�Ԫ�ص���
	while (++j < _size) // ��һɨ�裬ֱ��ĩԪ��
		if (_elem[i] != _elem[j]) // ������ͬ��
			_elem[++i] = _elem[j]; // ���ֲ�ͬԪ��ʱ����ǰ����������ǰ���Ҳ�
	_size = ++i; shrink(); // ֱ�ӽس�β������Ԫ��
	return j - i; // ���ر�ɾ��Ԫ������
}