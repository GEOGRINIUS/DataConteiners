#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------------\n"

void Elevator(int floor);
int Factorial(int n);
double Power(double a, int n);

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello world!" << endl;
	int n;
	int a;
	int b;
	//cout << "Введите номер этажа: "; cin >> n;
	//Elevator(n);
	/*cout << "Введите число: "; cin >> n;
	cout << Factorial(n) << endl;*/

	cout << "Введите положительное или отричательное значение: "; cin >> b;
	cout << "Введите основание степени: "; cin >> a;
	cout << "Введите показатель степени: "; cin >> n;
	cout << Power(a, n) << endl;

	main();
}

void Elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Вы в подвале" << endl;
		return;
	}
	cout << "Вы на " << floor << " Этаже" << endl;
	Elevator(floor-1);
	cout << "Вы на " << floor << " Этаже" << endl;
}

int Factorial(int n)
{
	return n == 0 ? 1 : n * Factorial(n - 1);
	/*if (n == 0) return 1;
	else return n*factorial(n - 1);*/
}

double Power(double a, int n, int b)
{
	return n == 0 ? 1 : n > 0 ? a * Power(a, n - 1) : 1 / Power(a, -n);

	/*if (n == 0)return 1;
	else if (n > 0) return a * Power(a, n - 1);
	else return 1 / Power(a, -n);*/
	//else return 1 / a * Power(a, n + 1);
}
