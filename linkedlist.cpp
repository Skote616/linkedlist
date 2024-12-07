// linkedlist.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;

	Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
public:
	Node* head;
	Node* tail;

public:
	DoublyLinkedList()
	{
		this->head = this->tail = NULL;
	}
public:
	void push_front(int data) {

		Node* node = new Node(data);
		node->next = head;
		if (head == NULL)
		{
			head = node;
		    tail = node;
		}
		else {
			head->prev = node;
			node->next = head;
			head = node;
		}
		std::cout << "Элемент добавлен\n";
		
		
	}

	void push_back(int data)
	{
		Node* node = new Node(data);
		node->prev = tail;
		if (tail == NULL)
		{
			head = node;
			tail = node;
		}
		else {
			tail ->next = node;
			node->prev = tail;
			tail = node;
		}
		std::cout << "Элемент добавлен\n";
		
	}

	void pop_front()
	{
		if (head != NULL)
		{
			Node* node = head->next;
			if (node != NULL)
				node->prev = NULL;
			else
				tail = NULL;
			head = node;
			std::cout << "Элемент удален\n";
		}
		else
			std::cout << "Список пуст\n";
	}

	void pop_back()
	{
		if (tail != NULL)
		{
			Node* node = tail->prev;
			if (node != NULL)
				node->next = NULL;
			else
				head = NULL;
			tail = node;
			std::cout << "Элемент удален\n";
		}
		else
			std::cout << "Список пуст\n";
		
	}

	void sort()
	{
		if (head == NULL || head->next == NULL) {
			std::cout << "Список пуст или элемент один\n";
			return;
		}
		Node* node = head;
		while (node!=nullptr)
		{
			Node* past = node->next;
			while (past != nullptr) 
			{
				if (node->data > past->data)
				{
					int temp = past->data;
					past->data = node->data;
					node->data = temp;
				}
				past = past->next;
				
			}
			node = node->next;
			delete past;
		}
		delete node;
		std::cout << "Список отсортирован\n";
	}

	void remove_duplicates()
	{
		if (head == NULL || head->next == NULL) {
			std::cout << "Список пуст или элемент один\n";
			return;
		}

		Node* node = head;
		while (node != nullptr) {
			Node* runner = node->next;
			while (runner != nullptr) {
				if (runner->data == node->data) {
					Node* temp = runner;
					runner = runner->next;
					if (temp->prev != nullptr) {
						temp->prev->next = temp->next;
					}
					if (temp->next != nullptr) {
						temp->next->prev = temp->prev;
					}
					delete temp;
				}
				else {
					runner = runner->next;
				}
			}
			node = node->next;
		}
		std::cout << "Операция выполнена\n";

		if (head == NULL || head->next == NULL) {
			std::cout << "Список пуст или элемент один\n";
			return;
		}
	}

	void display()
	{
		if (head != NULL)
		{
			Node* node = head;
			while (node)
			{    
				std::cout << node->data << "\n";
				node = node->next;
			}
			
		}
		else
			std::cout << "Список пуст\n";
	}


};

int main()
{
	setlocale(LC_ALL, "Russian");

	DoublyLinkedList list = DoublyLinkedList();
	char answ=' ';
	while (true)
	{
		while (answ != '1' && answ != '2' && answ != '3' && answ != '4' && answ != '5' && answ != '6' && answ != '7' && answ!='8')
		{
			std::cout << "\nВыберите интересующее вас действие и введите цифру:\n 1.Добавить элемент в начало.\n 2.Добавить элемент в конец.\n3.Удалить элемент с начала. \n4.Удалить элемент с конца.\n5.Отобразить список.\n6.Сортировать список.\n7.Удалить дубликаты. \n8.Выйти.\n";
			std::cin >> answ;
			std::cout << "\n";
		}

		int value;

		switch (answ)
		{
			case '1':
			{
				std::cout << "Введите число с которым будет выполнена операция\n";
				std::cin >> value;
				list.push_front(value);
				break;
			}
			case '2':
			{
				std::cout << "Введите число с которым будет выполнена операция\n";
				std::cin >> value;
				list.push_back(value);
				break;
			}
			case '3':
			{
				list.pop_front();
				break;
			}
			case '4':
			{
				list.pop_back();
				break;
			}
			case '5':
			{
				list.display();
				break;
			}
			case '6':
			{
				list.sort();
				break;
			}
			case '7':
			{
				list.remove_duplicates();
				break;
			}
			case '8':
			{
				std::cout << "До свидания!";
				return 0;
				break;
			}
			default:
			{
				std::cout << "До свидания!";
				return 0;
				break;
			}
			
		}
		answ = '0';
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
