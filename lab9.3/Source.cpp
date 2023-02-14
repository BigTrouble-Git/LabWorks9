#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;

struct Student
{
	string name;
	string prizv;
	string znak;

};
struct Data
{
	double day;
	double month;
	double year;
	int** a = new int* [3];

};
void Create(Student* p, Data* s, const int N);
void Print(Student* p, Data* s, const int N);
void Print1(Student* p, Data* s, int i);
void Sort(Student* p, Data* s, const int N);
void SaveToFile(Student* p, Data* s ,const int N, const char* filename);
void LoadFromFile(Student*& p, Data* s, int& N, const char* filename);
int BinSearch(Student* p,  const int N, const string prizv);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введіть кількість людей N: "; cin >> N;
	Student* p = new Student[N];
	Data* s = new Data[N];
	double proc, avg, MathG, average;
	string prizv;
	int found;
	int** a = new int* [3];
	for (int i = 0; i < 3; i++)
		a[i] = new int[3];
	char filename[100];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl;
		cout << " [4] - бінарний пошук студента за  прізвищем" << endl;
		cout << " [5] - запис даних у файл" << endl;
		cout << " [6] - зчитування даних із файлу" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, s, N);
			break;

		case 2:
			Print(p, s, N);
			break;

		case 3:
			Sort(p, s, N);
			break;
		case 4:
			cout << "Введіть ключі пошуку:" << endl;
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			cout << "Введіть прізвище: "; getline(cin, prizv);
			if ((found = BinSearch(p, N, prizv)) != -1) {
				cout << found + 1 << endl;
				Print1(p, s, found);
			}
			else
				cout << "Шуканого студента не знайдено" << endl;
			break;
		case 5:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			SaveToFile(p, s, N, filename);
			break;
		case 6:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			LoadFromFile(p, s, N, filename);
			break;

		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;

		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, Data* s, const int N)
{
	int Predmet;
	for (int i = 0; i < N; i++)
	{
		int n = 0;
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "Ім'я :"; getline(cin, p[i].name);
		cout << "Прізвище : "; getline(cin, p[i].prizv);
		cout << "Знак зодіаку : "; cin >> p[i].znak;
		cout << "День : "; cin >> s[i].day;
		cout << "Місяць : "; cin >> s[i].month;
		cout << "Рік : "; cin >> s[i].year;

		cout << endl;
	}
}
void Print1(Student* p, Data* s, int i)
{
	cout << "========================================================================="
		<< endl;
	cout << "__________________________________________|      День народження        |"
		<< endl;
	cout << "|  №  |  Ім'я  | Прізвище | Знак зодіаку  |  День  |  Місяць  |   Рік   |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;


	cout << "| " << setw(3) << right << i + 1 << " ";
	cout << "| " << setw(7) << left << p[i].name
		<< "| " << setw(9) << left << p[i].prizv
		<< "| " << setw(14) << left << p[i].znak
		<< "| " << setw(6) << right << s[i].day << " "
		<< "| " << setw(8) << right << s[i].month << " "
		<< "| " << setw(7) << right << s[i].year << " |" << endl;


	cout << "========================================================================="
		<< endl;
	cout << endl;
}
void Print(Student* p, Data* s, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "__________________________________________|      День народження        |"
		<< endl;
	cout << "|  №  |  Ім'я  | Прізвище | Знак зодіаку  |  День  |  Місяць  |   Рік   |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(7) << left << p[i].name
			<< "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(14) << left << p[i].znak
			<< "| " << setw(6) << right << s[i].day << " "
			<< "| " << setw(8) << right << s[i].month << " "
			<< "| " << setw(7) << right << s[i].year << " |" << endl;

	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* p, Data* s, const int N)
{
	Data tmp; Student tmp1;
	double avg1, avg2;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {

			if (s[i1].year > s[i1 + 1].year
				||
				s[i1].year == s[i1 + 1].year &&
				s[i1].month > s[i1 + 1].month
				||
				s[i1].year == s[i1 + 1].year &&
				s[i1].month == s[i1 + 1].month &&
				s[i1].day > s[i1 + 1].day)
			{
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;

				tmp1 = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp1;
			}
		}
}


int BinSearch(Student* p, const int N, const string prizv)
{
	int L = 0, R = N - 1, m;
	{
		do {
			m = (L + R) / 2;
			if (p[m].prizv == prizv)
				return m;
			if (p[m].prizv == prizv)
			{
				L = m + 1;
			}
			else
			{
				R = m - 1;
			}
		} while (L <= R);
		return -1;
	}
}

void SaveToFile(Student* p, Data* s, const int N, const char* filename)

{
	ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
	fout.write((char*)&N, sizeof(N)); // записали кількість елементів
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Student)); // записали елементи масиву
	fout.close(); // закрили файл
}
void LoadFromFile(Student*& p, Data* s, int& N, const char* filename)
{
	delete[] p; // знищили попередні дані
	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	p = new Student[N]; // створили динамічний масив
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Student)); // прочитали елементи масиву
	fin.close(); // закрили файл
}

