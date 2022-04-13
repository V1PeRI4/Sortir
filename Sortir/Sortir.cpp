#include <iostream>
#include <clocale>
#include <Windows.h>
#include <list>
using namespace std;

struct Buyer
{
	string name;
	string surname;
	string fathersname;
	string adress;
	string dateofdeal;
};

void createBuyer(Buyer(&obj));
void printBuyers(Buyer(&obj));
void deleteArray(Buyer* obj);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Russian");

	int arrayLength;

	Buyer* Buyers;

	cout << "Введите количество покупателей: ";
	cin >> arrayLength;

	Buyers = new Buyer[arrayLength];

	for (int i = 0; i < arrayLength; i++)
	{
		createBuyer(Buyers[i]);
	}
	setlocale(LC_ALL, "Russian");

	//Sort
	int tempNum;
	char tempChar[128];

	Buyer* Temp;
	Temp = new Buyer[arrayLength];

	int indexofequal;

	for (int i = 0; i < arrayLength; i++)
	{
		if (Buyers[i].name == Buyers[i + 1].name)
		{
			if (Buyers[i].adress == Buyers[i + 1].adress)
			{
				indexofequal = i + 1;
			}
		}
	}

	for (int i = 0; i < arrayLength; i++)
	{
		if (i != indexofequal)
		{
			Temp[i] = Buyers[i];
		}
		else
		{
			continue;
		}
	}
	cout << R"(
______                             _ _     _   
| ___ \                           | (_)   | |  
| |_/ /_   _ _   _  ___ _ __ ___  | |_ ___| |_ 
| ___ \ | | | | | |/ _ \ '__/ __| | | / __| __|
| |_/ / |_| | |_| |  __/ |  \__ \ | | \__ \ |_ 
\____/ \__,_|\__, |\___|_|  |___/ |_|_|___/\__|
              __/ |                            
             |___/                             
)" << '\n';

	for (int i = 0; i < arrayLength - 1; i++)
		printBuyers(Temp[i]);
}

void createBuyer(Buyer(&obj))
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите Имя: ";
	cin >> obj.name;

	cout << "Введите Фамилию: ";
	cin >> obj.surname;

	cout << "Введите Отчество: ";
	cin >> obj.fathersname;

	cout << "Введите адрес: ";
	cin >> obj.adress;

	cout << "Введите дату учета: ";
	cin >> obj.dateofdeal;


}

void printBuyers(Buyer(&obj))
{
	setlocale(LC_ALL, "Russian");

	cout << "Имя - " << obj.name << endl;
	cout << "Фамилия - " << obj.surname << endl;
	cout << "Отчество - " << obj.fathersname << endl;
	cout << "Адрес - " << obj.adress << endl;
	cout << "Дата Учета - " << obj.dateofdeal << endl;
	cout << endl;
}

void deleteArray(Buyer* obj)
{
	setlocale(LC_ALL, "Russian");

	delete[] obj;
	cout << "Список удалён" << endl;
}


//SUS