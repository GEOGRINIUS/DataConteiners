#pragma warning (disable:4326)
#include<iostream>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------------\n"

class List
{
	class element
	{
		int Data;
		element* pNext;
		element* pPrev;
		List* Temp;
	public:
		element(int Data, element* pNext = nullptr, element* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head,*Tail;
	size_t size;
public:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const std::initializer_list<int>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); ++it)
			push_back(*it);
	}
	~List()
	{

		while (Tail)pop_back();
		//while (Head)pop_front();
		cout << "LDestructor\t" << this << endl;
	}

//				Adding elements:
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
			Head = Tail = new element(Data);
		else
			Head = Head->pPrev = new element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
			Head = Tail = new element(Data);
		else
			Tail = Tail->pNext = new element(Data, nullptr, Tail);
		size++;
	}
//				Removing elements:
	void pop_front()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
		}
		else
		{
			Head = Head->pNext;
			delete Head->pPrev;
			Head->pPrev = nullptr;
		}
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr && Tail == nullptr)return;
		if (Head == Tail)
		{
			delete Tail;
			Head = Tail = nullptr;
		}
		else
		{
			Tail = Tail->pPrev;
			delete Tail->pNext;
			Tail->pNext = nullptr;
		}
		size--;
	}
	void insert(int Data, int Index)
	{
		if (Index >= size)return;
		if (Index == size - 1)return push_back(Data);
		if (Index == 0)return push_front(Data);
		element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext->pPrev =
			new element(Data, Temp->pNext, Temp->pPrev);
		size++;
	}
	void erase(int index)
	{
		if (index >= size)return;
		if (index == size - 1)return pop_back();
		if (index == 0)return pop_front();
		//1) Доходим до нужного элеменета:
		element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
		}
		//2) Исключаем адуляемый элемент из списка:
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		//3) Удаляем элемент из памяти: 
		delete Temp;
		//4) Decrement: 
		size--;
	}

//				Methods:
	void print()const
	{
		cout << "Head:\t" << Head << endl;
		for (element* Temp = Head; Temp; Temp=Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Tail:\t" << Tail << endl;
		cout << "Количество элементов в списке: " << size << endl;
	}
	void reverse_print()const
	{
		cout << "Tail:\t" << Tail << endl;
		for (element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
		cout << "Head:\t" << Head << endl;
	}
};

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();
	
	int index;
	int value;

	/*cout << "Введите индекс добывляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(value, index);*/

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	
	list.print();
	list.reverse_print();
#endif // BASE_CHECK
	

	List list = { 3, 5, 8, 13, 21 };
	//list.print();
	for (int i : list) cout << i << tab; cout << endl;


}  