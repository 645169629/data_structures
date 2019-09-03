#include <iostream>
#include "vector.h"
#include "permute.h"

using namespace std;

int main() 
{
	int a[] = { 1, 2, 3, 4 };
	// 测试构造函数，从数组复制
	Vector<int> V (a, 4);
	// 测试赋值操作符
	Vector<int> V1;
	V1 = V;
	// 测试下标操作符
	cout << V[0] << endl;
	// 测试置乱向量
	permute(V);
	cout << V[0] << endl;

}