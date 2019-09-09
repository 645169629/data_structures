#pragma once
#include "../fibonacci/fib.h"

// ����������������[lo,hi)�ڣ�ȷ��������e�����һ���ڵ����
template <typename T> Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
	// ��50%�ĸ������ʹ�ö��ֲ��һ�Fibonacci����
	return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(-elem, e, lo, hi);
}

// Fibonacci�����㷨���汾A��������������������[lo,hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> static Rank fibSearch(T * A, T const& e, Rank lo, Rank hi) {
	Fib fib(hi - lo); // ��O(log_phi(n = hi - lo)ʱ�䴴��Fib����)
	while (lo < hi) { // ÿ����������Ҫ�����αȽ��жϣ���������֧
		while (hi - lo < fib.get()) fib.prev(); // ͨ����ǰ˳����ң���̯O(1)��
		Rank mi = lo + fib.get() - 1; // ȷ������Fib(k) - 1�����
		if (e < A[mi]) hi = mi; // ����ǰ���[lo,hi)��������
		else if (A[mi] < e) lo = mi + 1; // ������Σ�mi, hi����������
		else return mi; // ��mi������
	} // �ɹ����ҿ�����ǰ��ֹ
	return -1; // ����ʧ��
} // �ж������Ԫ��ʱ�����ܱ�֤����������ߣ�ʧ��ʱ���򵥵ķ���-1��������ָʾʧ�ܵ�λ��

// ���ֲ����㷨���汾A��������������������[lo,hi)�ڲ���Ԫ��e
template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
	while (lo < hi) { // ÿ����������Ҫ�����αȽ��жϣ���������֧
		Rank mi = (lo + hi) >> 1; // ���е�Ϊ���
		if (e < A[mi]) hi = mi; // ����ǰ���[lo,hi)��������
		else if (A[mi] < e) lo = mi + 1; // �������(mi,hi)��������
		else return mi; // ��mi������
	}
	return -1; // ����ʧ��
} // �ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���򵥵ķ���-1��������ָʾʧ�ܵ�λ��

// ���ֲ����㷨���汾B��������������������[lo,hi)�ڲ���Ԫ��e�� 0 <= lo <= hi <= _size
template<typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
	while (1 < hi - lo) { // ÿ������������һ�αȽ��жϣ���������֧���ɹ����Ҳ�����ǰ��ֹ
		Rank mi = (lo + hi) >> 1; // ���е�Ϊ���
		��e < A[mi]�� ? hi = mi : lo = mi; // ���ȽϺ�ȷ������[lo, hi)��[mi, hi)
	}// ����ʱhi = lo +1�������������һ��Ԫ��A[lo]
	return (e == A[lo]) ? lo : -1; // ���ҳɹ�ʱ���ض�Ӧ���ȣ�����ͳһ����-1
} // �ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���򵥷���-1��������ָʾʧ�ܵ�λ��

// ���ֲ����㷨���汾C��������������������[lo,hi)�ڲ���Ԫ��e, 0 <= lo <= hi <= _size
template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1; // ���ȽϺ�ȷ������[lo,mi) �� (mi,hi)
	} // �ɹ����Ҳ�����ǰ��ֹ
	return --lo; //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ���lo-1��������e�������
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���ܹ�����ʧ�ܵ�λ�� 

