#include <iostream>
#include "vector.h"
#include "permute.h"

using namespace std;

int main() 
{
	int a[] = { 1, 2, 3, 4 };
	// ���Թ��캯���������鸴��
	Vector<int> V (a, 4);
	// ���Ը�ֵ������
	Vector<int> V1;
	V1 = V;
	// ���Բ������
	V.insert(0, 10);
	V.traverse();
	// ����ɾ������
	V.remove(0, 2);
	V.remove(0);
	// �����±������
	cout << V[0] << endl;
	// ����������������
	cout << V.find(1) << endl;
	// ����Ψһ������
	V.insert(1);
	V.insert(0, 1);
	V.insert(3, 1);
	V.traverse();
	V.deduplicate();
	V.traverse();
	// ������������
	permute(V);
	cout << V[0] << endl;

}