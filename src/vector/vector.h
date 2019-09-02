#pragma once
typedef int Rank; // �ȣ��±꣩
#define DEFAULT_CAPACITY 3 // Ĭ�ϵĳ�ʼ����

template <typename T> class Vector { // ����ģ����
protected:
	Rank _size; int _capacity; T* _elem; // ��ģ��������������
	void copyFrom(T const* A, Rank lo, Rank, hi); //������������ A[lo, hi)
	void expand(); // �ռ䲻��ʱ����
	void shrink(); // װ�����ӹ�Сʱѹ��
	bool bubble(Rank lo, Rank hi); // ɨ�轻��
	void bubbleSort(Rank lo, Rank hi); // ð�������㷨
	Rank max(Rank lo, Rank hi); // ѡȡ���Ԫ��
	void selectionSort(Rank lo, Rank hi); // ѡ������
	void merge(Rank lo, Rank hi); // �鲢�㷨
	void mergeSort(Rank lo, Rank hi); // �鲢�����㷨
	Rank partition(Rank lo, Rank hi); // ��㣨pivot�������㷨
	void quickSort(Rank lo, Rank hi); // ���������㷨
	void heapSort(Rank lo, Rank hi); // ������
public:
	// ���캯��
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) // ����Ϊc����ģΪs������Ԫ�س�ʼΪv
	{
		_elem = new T[_capacity = c]; // ��ʼ��һ������Ϊ c ����
		for (_size = 0; _size < s; _elem[_size++] = v); // Ϊ����ÿ��Ԫ�ظ�ֵ
	}
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); } // �������帴��
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } // �������临��
	Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); } // �������帴��
	Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi) }; // �������临��
	// ��������
	~Vector() { delete[] _elem; } // �ͷ��ڲ��ռ�
	// ֻ�����ʽӿ�
	Rank size() const { return _size; } // ��ģ
	bool empty() const { return !_size; } // �п�
	int disordered() const; //�ж������Ƿ�����
	Rank find(T const& e) const { return find(e, 0, _size); } // ���������������

};
