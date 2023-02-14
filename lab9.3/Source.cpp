#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
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
	cout << "������ ������� ����� N: "; cin >> N;
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
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������� ������������� �����" << endl;
		cout << " [4] - ������� ����� �������� ��  ��������" << endl;
		cout << " [5] - ����� ����� � ����" << endl;
		cout << " [6] - ���������� ����� �� �����" << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "������ ����� ������:" << endl;
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
			cout << "������ �������: "; getline(cin, prizv);
			if ((found = BinSearch(p, N, prizv)) != -1) {
				cout << found + 1 << endl;
				Print1(p, s, found);
			}
			else
				cout << "�������� �������� �� ��������" << endl;
			break;
		case 5:
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			SaveToFile(p, s, N, filename);
			break;
		case 6:
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			LoadFromFile(p, s, N, filename);
			break;

		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;

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
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "��'� :"; getline(cin, p[i].name);
		cout << "������� : "; getline(cin, p[i].prizv);
		cout << "���� ������ : "; cin >> p[i].znak;
		cout << "���� : "; cin >> s[i].day;
		cout << "̳���� : "; cin >> s[i].month;
		cout << "г� : "; cin >> s[i].year;

		cout << endl;
	}
}
void Print1(Student* p, Data* s, int i)
{
	cout << "========================================================================="
		<< endl;
	cout << "__________________________________________|      ���� ����������        |"
		<< endl;
	cout << "|  �  |  ��'�  | ������� | ���� ������  |  ����  |  ̳����  |   г�   |"
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
	cout << "__________________________________________|      ���� ����������        |"
		<< endl;
	cout << "|  �  |  ��'�  | ������� | ���� ������  |  ����  |  ̳����  |   г�   |"
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
	ofstream fout(filename, ios::binary); // ������� ������� ���� ������
	fout.write((char*)&N, sizeof(N)); // �������� ������� ��������
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Student)); // �������� �������� ������
	fout.close(); // ������� ����
}
void LoadFromFile(Student*& p, Data* s, int& N, const char* filename)
{
	delete[] p; // ������� �������� ���
	ifstream fin(filename, ios::binary); // ������� ������� ���� ����������
	fin.read((char*)&N, sizeof(N)); // ��������� ������� ��������
	p = new Student[N]; // �������� ��������� �����
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Student)); // ��������� �������� ������
	fin.close(); // ������� ����
}

