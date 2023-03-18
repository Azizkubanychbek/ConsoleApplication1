#include <iostream>

#define MODE 9
#if MODE==1
void add(int j, int b)
{
	std::cout << j + b;

}
#endif
int main() {
#ifndef MODE
#error Where is MODE?
#endif // !MODE

#ifdef MODE
#if MODE==0
	std::cout << "Работаю в режиме тренировки";
#elif MODE==1
	int j = 9;
	int b = 0;

	std::cout << "Работаю в боевом режиме\n";
	std::cout << "Ввeдите два числа через enter\n";
	std::cin >> b >> j;
	std::cout << "Сумма равна ";
	add(b, j);

#else
	std::cout << "Неизвестный режим. Завершение работы";
#endif 
#endif
}
