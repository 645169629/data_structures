#pragma once

template<typename T> void Vector<T>::traverse() {
	for (int i = 0; i < _size; i++) cout<<_elem[i]<<",";
	cout << endl;
}
template <typename T> void Vector<T>::traverse(void(*visit) (T&)) { // ��������ָ�����
	for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T> template <typename VST> // Ԫ�����͡�������
void Vector<T>::traverse(VST& visit) { // ���������������
	for (int i = 0; i < _size; i++) visit(_elem[i]);
}