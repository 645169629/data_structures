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
	// 测试插入操作
	V.insert(0, 10);
	V.traverse();
	// 测试删除操作
	V.remove(0, 2);
	V.remove(0);
	// 测试下标操作符
	cout << V[0] << endl;
	// 测试无序向量查找
	cout << V.find(1) << endl;
	// 测试唯一化操作
	V.insert(1);
	V.insert(0, 1);
	V.insert(3, 1);
	V.traverse();
	V.deduplicate();
	V.traverse();
	// 测试置乱向量
	permute(V);
	cout << V[0] << endl;

}