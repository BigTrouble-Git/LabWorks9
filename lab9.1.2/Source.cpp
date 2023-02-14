#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h> // забезпечення відображення кирилиці 
using namespace std;

enum Fahoviy { PROGRAMUVANNA, CHSLMETOD, PEDAGOGIKA };
string predmetStr[] = { "Програмування  ", "Чисельні методи", "Педагогіка     " };
struct Student
{
    string prizv;
    string kurs;
    union
    {
        unsigned fizyka;
    };
    union
    {
        unsigned matematyka;
    };
    Fahoviy specialnist;
    union
    {
        unsigned programuvanna;
        unsigned chslmetod;
        unsigned pedagogika;
    };
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Amount(Student* p, const int N);
double Average_of_Student(Student* p, const int N);
int main()
{ // забезпечення відображення кирилиці: 
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу 
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу 

    int N;
    cout << "Введіть N: "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    double amount = Amount(p, N);
    cout << "Відсоток студентів, які отримали з фізики оцінки 5 або 4 = " << amount << " %";
    cout << endl;
    double maxim = Average_of_Student(p, N);
    cout << "Найбільший середній бал = " << maxim;
    return 0;
}
void Create(Student* p, const int N)
{
    int Predmet;
    for (int i = 0; i < N; i++)
    {
        int n = 0;
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get(); // очищуємо буфер клавіатури – бо залишаються символи 
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок 

        cout << " прізвище: "; getline(cin, p[i].prizv);
        cout << " курс: "; getline(cin, p[i].kurs);
        cout << " Бал з фізики: "; cin >> p[i].fizyka;
        cout << " Бал з математики: "; cin >> p[i].matematyka;
        cout << " посада (0 - програмування, 1 - чисельні методи, 2 - педагогіка): ";
        cin >> Predmet;
        p[i].specialnist = (Fahoviy)Predmet;
        switch (p[i].specialnist)
        {
        case PROGRAMUVANNA:
            cout << " Бал з програмування : "; cin >> p[i].programuvanna;
            break;
        case CHSLMETOD:
            cout << " Бал з чисельних методів : "; cin >> p[i].chslmetod;
            break;
        case PEDAGOGIKA:
            cout << " Бал з педагогіки : "; cin >> p[i].pedagogika;
            break;
        }
        cout << endl;
    }
}
double Average_of_Student(Student* p, const int N) {
    double maxim = 0;
    double avg;
    for (int i = 0; i < N; i++)
    {
     
        avg = (p[i].fizyka + p[i].matematyka + p[i].programuvanna) / 3.0;


        if (avg > maxim)
            maxim = avg;

    }

    return maxim;
}

double Amount(Student* p, const int N)
{

    int k = 0, n = 0;
    int nloc = 0;
    for (int i = 0; i < N; i++)
    {
        if (true)
        {
            n++;
            if (p[i].fizyka == 5 || p[i].fizyka == 4)
            {
                k++;
                nloc += k;
            }
        }
    }

    return 100.0 * k / n;
}

void Print(Student* p, const int N)
{
    cout << "====================================================================================================================="
        << endl;
    cout << "____________________________________________|                               Бали                                    |"
        << endl;
    cout << "|  №  |  Прізвище  | Курс | Спеціальність   |  Фізика  |  Математика  | Програмування | Чисельні методи | Педагогіка|"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(3) << left << p[i].prizv << "     "
            << "| " << setw(3) << right << p[i].kurs << "  "
            << "| " << setw(11) << left << predmetStr[p[i].specialnist]<< " "
            << "| " << setw(7) << right << p[i].fizyka << "  "
            << "| " << setw(10) << right << p[i].matematyka << "   ";
        switch (p[i].specialnist)
        {
        case PROGRAMUVANNA:
            cout << "| " << setw(13) << right << p[i].programuvanna << " |" << setw(18) << right << "|" << setw(12) << right << "|" << endl;
            break;
        case CHSLMETOD:
            cout << "| " << setw(15) << right << "|" << " " << setw(15) << right << p[i].chslmetod << " |" << setw(12) << right << "|" << endl;
            break;
        case PEDAGOGIKA:
            cout << "| " << setw(15) << right << "|" << " " << setw(18) << right << "| " << " " << setw(8) << right << p[i].pedagogika << " |" << endl;
            break;
        }

    }
    cout << "====================================================================================================================="
        << endl;
    cout << endl;
}
