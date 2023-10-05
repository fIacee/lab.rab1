#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void bites() { // данная функция просто выводит число байт выделяемых компьютером для разных типов данных.
	cout << "Кол-во байт для int: " << sizeof(int) << "\n";
	cout << "Кол-во байт для short int: " << sizeof(short int) << "\n";
	cout << "Кол-во байт для float: " << sizeof(float) << "\n";
	cout << "Кол-во байт для double: " << sizeof(double) << "\n";
	cout << "Кол-во байт для long double: " << sizeof(long double) << "\n";
	cout << "Кол-во байт для char: " << sizeof(char) << "\n";
	cout << "Кол-во байт для bool: " << sizeof(bool) << "\n";
}

void input1() { // данная функция выводит побитовое представление целого числа.
	int value1;
	unsigned int order1(sizeof(int) * 8);
	cout << "Введите целочисленное значение: ";
	scanf("%d", &value1);
	unsigned int mask1 = 1 << order1 - 1;
	
	system("cls");
	for (int i = 1; i <= order1; i++) {
		cout << ((value1 & mask1) ? '1' : '0');
			mask1 >>= 1;
			if (i % 8 == 0 || i % order1 - 1 == 0) {
				cout << " ";
			}
	}
	
	cout << "\n";
	return;
}

void input2() // данная функция выводит побитовое представление вещественного числа.
{
	union {
		int value2;
		float value2f;
	};
	cout << "Введите вещественное значение: ";
	cin >> value2f;
	unsigned int order2 = sizeof(int) * 8;
	unsigned int mask2 = 1 << order2 - 1;
	for (int i = 1; i <= order2; i++) {
		putchar(value2 & mask2 ? '1' : '0');
		mask2 >>= 1;
		if (i == 9 || i == 2 || i % order2 - 1 == 0) {
			putchar(' ');
		}
	}
	cout << '\n';
}



int main() {
	setlocale(LC_ALL, "Russian");

	while (1) { // это бесконечный цикл меню.
		cout << "   Меню:\n1. Вывести кол-во байт, которое компьютер выделяет под разные типы данных.\n2. Вывести побитовое представление целого числа.\n3. Вывести побитовое представление вещественного числа.\n\nЧтобы выйти введите x или X.\n\n";;
		string inputer;
		cin >> inputer;
		if (inputer == "1") {
			system("cls");
			bites();
			system("pause");
			system("cls");
			continue;
		}
		if (inputer == "2") {
			system("cls");
			input1();
			system("pause");
			system("cls");
			continue;
		}
		if (inputer == "3") {
			system("cls");
			input2();
			system("pause");
			system("cls");
			continue;
		}
		if (inputer == "x" || inputer == "X") {
			system("cls");
			exit(1);
		}
		else {
			system("cls");
			cout << "Вы ввели недопустимое значение!\n";
			system("pause");
			system("cls");
			continue;
		}
	}
}