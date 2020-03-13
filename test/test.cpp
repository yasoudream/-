// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main(int argc, char *argv[])
{
	printf_s("wtf?\n");
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}
	printf_s("wtf2?\n");
	getchar();
	return 0;
}
