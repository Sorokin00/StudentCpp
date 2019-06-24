#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
class collection
{
public:
	collection();
	~collection();

	void push(T data)
	{
		if (first_element == nullptr) // проверяем пустой ли первый элемент или нет
		{
			first_element = new element<T>(data); // если пустой, то заполняем его получеными данными
		}
		else
		{
			element<T> *temp = this->first_element; // если первый элемент уже заполнен, тогда создадим времменную переменную, чтобы добавить новый элемент в список
			while (temp->Next != nullptr) {
				temp = temp->Next;
			}
			temp->Next = new element<T>(data);
		}
		Size++;
	}
	int get_size() { return Size; } // создадим метод для того чтобы вывести размер списка (понадобится для вывода всего списка)
	void clear(); // создадим метод удаления конкретного элемента из списка


	T& operator[](const int index); // перегрузим оператор [] чтобы перемещаться по списку 
	friend ostream& operator<<(ostream& out, const collection& point) // перегрузим оператор вывода
	{
		point.Temp = data.first_element;
		while (data.Temp != NULL)
		{
			out << data.Temp->data;
			data.Temp = data.Temp->Next;
		}
		return out;
	}
	friend istream& operator>>(istream & in, collection & point) // перегрузим оператор ввода
	{
		point.Temp = new element;
		point.Temp->Next = NULL;
		in >> point.Temp->data;
		point.push(point.Temp);
		return in;
	}

private:
	template<typename T>
	struct element // описываем элемент
	{
	public:
		element *Next; // создаем указатель на следующий элемент
		T data; // данные введеные пользователем

		element(T data = T(), element *Next = nullptr) // создаем конструктор к элементу и передаем туда данные
		{
			this->data = data;
			this->Next = Next;
		}
	};
	int Size; // создаем переменную, которая будет считать кол-во элементов в списке
	element<T> *first_element, *Temp; // создаем указатель на первый элемент списка
};

template <typename T>
collection<T>::collection() // конструктор, обнуляющий размер и первый элемент
{
	Size = 0;
	first_element = nullptr;
}

template <typename T>
collection<T>:: ~collection()
{
	clear(); // создаём деструктор для очистки всего списка
}

template<typename T>
void collection<T>::clear() // метод clear будет удалять все элементы списка, пока его первый элемент не будет равен нулю
{
	while (Size != 0)
	{
		element<T> *temp = first_element; // создаем временную переменную для того чтобы удалить первый элемент списка
		first_element = first_element->Next; // изменим указатель первого элемента на последующий, чтобы удалить его
		delete temp; // удаляем временную переменную
		Size--; // уменьшаем размер списка
	}

}

template<typename T>
T & collection<T>::operator[](const int index) // данный метод выводит всю информацию из ячейки которую указал пользователь
{
	int count = 0; // создадим счетчик, чтобы знать в каком элементе списка мы находимся
	element<T> *temp = this->first_element;
	while (temp != nullptr)
	{
		if (count == index)
		{
			return temp->data;
		}
		temp = temp->Next;
		count++;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream table;
	table.open("C:\\Users\\ILYA\\Desktop\\Курсработа\\Вариант 9\\table.txt"); // открываем файл
	if (!table) // проверяем, существует ли файл
	{
		cout << "Ошибка отсутствует файл " << endl;
		return -1;
	}
	else
	{
		ifstream fin; // создаем переменную для вывода всех данных из файла
		fstream fout; // создадим переменную для записи данных в файл
		char c; // создадим переменную для считывания файла
		collection<char> Kay; // ключ
		fin.open("table.txt"); // открываем файл "таблица", чтобы считать все данные оттуда
		while (fin.get(c)) // добавляем цикл while, который будет работать до тех пор, пока в файле не закончаться данные(считывание всего файла)
		{
			fin >> c;  // оператор считывания
			Kay.push(c);
		}
		fin.close();
		int poisk1;
		string poisk2;
		int operation = 0;
		cout << "Здравствуйте, вы открыли информационную систему железнодорожного вокзала." << "Что бы вы хотели сделать?" << endl <<
			"1) Добавить поезд." << endl <<
			"2) Вывести все рейсы." << endl <<
			"3) Поиск поезда по номеру." << endl <<
			"4) Поиск рейсов до станции." << endl <<
			"5) Выход." << endl;
		cin >> operation;
		switch (operation)
		{
		case 1:
			cout << "Введите номер поезда:" << endl;
			char num;
			cin >> num;
			Kay.push(num);
			break;

		case 2:
			cout << "Вся рейсы:" << endl;
			for (int i = 0; i < Kay.get_size(); i++)
			{
				cout << Kay[i] << " ";
			}
			cout << endl;
			break;

		case 3:
			cin >> poisk1;
			break;

		case 4:
			cin >> poisk2;
			break;

		case 5:
			remove("table.txt");// для перезаписи файла, нужно его очитстить
			fout.open("table.txt", fstream::app); // окрываем файл, арр-команда, которая не дает удалить данные из файла при завершений программы
			for (int i = 0; i < Kay.get_size(); i++)
			{
				fout << Kay[i] << endl;
			}
			fout.close();
			cout << "До свидания! " << endl;
			return 0;
		}
	}

}