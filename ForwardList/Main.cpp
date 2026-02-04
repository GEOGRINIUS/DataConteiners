#pragma warning (disable:4326)
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//ForwardList - односвязный список;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------------\n"

class Element
{
	int Data;		 //значение элемента;
	Element* pNext;  //указатель на следующий элемент;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
class ForwardList
{
	Element* Head;		//Голова списка - является точкой входа в список;
public:
	ForwardList()
	{
		//Конструктор по умолчанию создает пустой список;
		Head = nullptr;
		//Когда список пуст, его голова указывает на 0;
		cout << "Lconstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

//				Adding elements:
	void push_front(int Data)
	{
		//1) создаем добавляемый элемент:
		Element* New = new Element(Data);
		//2) Пристыковаем Новый элемент к началу списка:
		New->pNext = Head;
		//3) Смещаем Голову на Новый элемент:
		Head = New;
	}
	void push_back(int Data)
	{
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Доходим до конца списка:
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		//3) Добавляем элемент в конец списка:
		Temp->pNext = New;
	}

	//			Methods:
	void print()const
	{
		Element* Temp = Head;	//Temp - это Итератор.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; //Переход на следующий элемент.
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello ForwardList" << endl;

	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	list.push_back(123);
	list.print();
}