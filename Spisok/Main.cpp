#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;	//Значение элемента
	Element* pNext;//Адрес следующего элемента
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstrcutor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestrcutor:\t" << this << endl;
	}
	friend class ForwardList;
};
int Element::count = 0;

class ForwardList//Односвязный (однонаправленный) список
{
	Element* Head;	//Голова списка - указывает на начальный элемент списка.
public:
	ForwardList()
	{
		Head = nullptr;//Если голова указывает на 0, то список пуст.
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//					Addigng elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);//Создаем новый элемент и помещаем в него значение Data
		New->pNext = Head;	//Привязывем новый элемент к началу списка
		Head = New;	//Переводим Голову на новый элемент
	}
	void push_back(int Data)
	{
		//проверяем является ли список пустым:
		if (Head == nullptr)return push_front(Data);
		//создаем новый элемент
		Element* New = new Element(Data);
		//Доходим до конца списка:
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		//Теперь мы находимся в последнем элементе
		//Присоединяем новый элемент
		Temp->pNext = New;
	}
	void insert(int index, int Data)
	{

		if (index == 0 || Head == nullptr) return push_front(Data);
		if (index > Head->count)return;
		Element* New = new Element(Data);
		//Доходим до нужного элемента
		Element* Temp = Head;
		for (size_t i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		//Включаем новый элемент в список

		New->pNext = Temp->pNext;
		Temp->pNext = New;

	}
	//Removing elements:

	void pop_front()
	{
		if (Head == nullptr) return;
		//запоминаем адрес удаляемого элемента
		Element* Erased = Head;
		//исключаем удаляемый элемент
		Head = Erased->pNext;
		//Удаляем элемент из памяти
		delete Erased;
	}
	void pop_back()
	{
		if (Head == nullptr) return;
		if (Head->pNext == nullptr) return pop_front();
		//доходим до предпоследнего элемента:
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		//Удаляем элемент из памяти:
		delete Temp->pNext;
		//затираем адрес удаленного элемента нулем
		Temp->pNext = nullptr;
	}

	//					Methods:
	void print()const
	{
		int a = 2;
		int* pa = &a;
		Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это указатель, при помощи которого можно получить доступ 
		//к элементам структуры данных.
		while (Temp)//Пока Итератор содержит ненулевой адрес.
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//переход на следующий элемент
		}
		cout << "Колличество элементов списка: " << Head->count << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	list.pop_front();
	for (int i = 0; i < n; i++)
	{/*
		list.push_front(rand() % 100);*/
		list.push_back(rand() % 100);
	}
	list.print();
	/*list.push_back(123);*/

	/*list.pop_front();
	list.pop_back();
	list.print();*/
	int index;
	int value;
	cout << "ВВедите индекс добавляемого элемента: "; cin >> index;
	cout << "ВВедите значение добавляемого элемента: "; cin >> value;

	list.insert(index, value);
	list.print();


}