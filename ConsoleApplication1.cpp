﻿#include <iostream>

#define MODE 1
int main(int argc, char** argv) {
#ifndef MODE
	std::cout << "Where is MODE?";
#endif // !MODE
#ifdef MODE
#if MODE==0
	std::cout << "Работаю в режиме тренировки";
#elif MODE==1
	int j = 9;
	int b = 0;
	int add(int j,int b);
	{
		int l = j + b;
		return l;
	}
	std::cout << "Работаю в боевом режиме\n";
	std::cout << "Ввeдите два числа через enter\n";
	std::cin >> b >> j;
	std::cout << "Сумма равна " << add(b,j);
	
#else
	std::sout << "Try smt better";
#endif
#endif 
}