// Lab09_1(1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;
enum Posada { COMP, IT, MATH, PHYSIC, WORK };
enum Curs { FIRST, SECOND, THIRD, FOUR };

string cursStr[] = { "I", "II", "III", "IV" };
string posadaStr[] = { "Комп науки", "Інформатика", "Мат та ек", "Фіз та інформ", "Труд навч" };

struct Student
{
	string prizv;
	Curs curs;
	Posada posada;
	struct
	{
		int physic;
		int math;
		union
		{
			int IT;
			int nummetod;
			int pedagog;
		};
	};
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
int Students(Student* p, const int N);
double LineSearch(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	cout << "Кількість студентів, які вчаться без трійок: " << Students(p, N) << endl;
	cout << "Процент студентів, чий середній бал менший 4: " << LineSearch(p, N) << "%" << endl;

	return 0;

}
void Create(Student* p, const int N)
{
	int posada;
	int curs;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс (0 - I, 1 - II, 2 - III, 3 - IV): ";
		cin >> curs;
		cout << " спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> posada;
		cout << " оцінка з фізики : "; cin >> p[i].physic;
		cout << " оцінка з математики : "; cin >> p[i].math;
		p[i].posada = (Posada)posada;
		p[i].curs = (Curs)curs;
		switch (p[i].posada)
		{
		case COMP:
			cout << " оцінка з програмування : "; cin >> p[i].IT;
			break;
		case IT:
			cout << " оцінка з чисельних методів : "; cin >> p[i].nummetod;
			break;
		case MATH:
		case PHYSIC:
		case WORK:
			cout << " оцінка з педагогіки : "; cin >> p[i].pedagog;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "==========================================================================================================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з програмування | Оцінка з чисельних методів | Оцінка з педагогіки |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << i + 1;
		cout << "| " << setw(9) << p[i].prizv;
		cout << "| " << setw(5) << cursStr[p[i].curs];
		cout << "| " << setw(14) << posadaStr[p[i].posada];
		cout << "| " << setw(16) << p[i].physic;
		cout << "| " << setw(20) << p[i].math;
		switch (p[i].posada)
		{
		case COMP:
			cout << "| " << setw(23) << p[i].IT << "|" << setw(29) << "|" << setw(22) << "|";
			break;
		case IT:
			cout << "| " << setw(24) << "|" << setw(28) << p[i].nummetod << "|" << setw(22) << "|";
			break;
		case MATH:
		case PHYSIC:
		case WORK:
			cout << "| " << setw(24) << "|" << setw(29) << "|" << setw(21) << p[i].pedagog << "|";
			break;
		}
		cout << endl;
	}
	cout << "==========================================================================================================================================================="
		<< endl;
	cout << endl;
}
int Students(Student* p, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].posada == COMP || p[i].posada == IT ||
			p[i].posada == MATH || p[i].posada == PHYSIC ||
			p[i].posada == WORK)
		{
			if (p[i].physic >= 4 && p[i].math >= 4 &&
				(p[i].IT >= 4 || p[i].nummetod >= 4
					|| p[i].pedagog >= 4)) 
			{
				k++;
			}
		}
	}
	return k;
}
double LineSearch(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].posada == COMP || p[i].posada == IT || 
			p[i].posada == MATH || p[i].posada == PHYSIC || 
			p[i].posada == WORK)
		{
			n++;
			if (((p[i].physic + p[i].math + p[i].IT + 
				p[i].nummetod + p[i].pedagog) / 3) < 4)
			{
				k++;
			}
		}
	}
	return 100.0 * k / n;
}



