#pragma once

using namespace std;

template <typename T> void permute(Vector<T>& V) { // 随机置乱向量，使个元素等概率出现在各位置
	for (int i = V.size(); i > 0; i--) // 自后向前
		swap(V[i-1], V[rand() % i]);
}