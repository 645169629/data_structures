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
	// �����±������
	cout << V[0] << endl;
	// ������������
	permute(V);
	cout << V[0] << endl;

}