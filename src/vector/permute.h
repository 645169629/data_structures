#pragma once

using namespace std;

template <typename T> void permute(Vector<T>& V) { // �������������ʹ��Ԫ�صȸ��ʳ����ڸ�λ��
	for (int i = V.size(); i > 0; i--) // �Ժ���ǰ
		swap(V[i-1], V[rand() % i]);
}