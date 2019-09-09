#pragma once

#include<stdio.h>

template <typename T> static void print(T* x) { x ? print(*x) : printf("<NULL>"); }
static void print(char* x) { printf("%s", x ? x : "<NULL>"); } // �ַ����ر���
static void print(const char* x) { printf("%s", x ? x : "<NULL>"); } // �ַ������⴦��