#pragma once

// 删除无序向量中重复元素
template <typename T> int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1; // 从_elem[1]开始
	while (i < _size) // 自前向后逐一考查各元素_elem[i]
		find(_elem[i], 0, i) < 0  ? i++ : remove(i); // 在前缀中寻找与之类同者，若无雷同则继续考查后继，否者删除类同者
	return oldSize - _size;
}