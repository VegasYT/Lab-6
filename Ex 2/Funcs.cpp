#include <iostream>
#include "Funcs.h"

using namespace std;


void getGroup(Student* array) // ������� ��� ���������� ��� ��������
{
	for (int i{ 0 }; i < Constants::numStud; ++i)
	{
		array[i].id = i + 1;
		cout << "������� N" << array[i].id << ": ";
		getline(cin >> ws, array[i].fio);
	}
}


void getScoreRate(Student* array, int num) // ������� ��� ��������� ������ ��������
{
	if (num < 0 || num > Constants::numStud - 1) 
		return;

	cout << "������ �������� " << array[num].fio << ": ";
	for (int i{0}; i < Constants::scoreRate1 + Constants::scoreRate2; i++)
		cin >> array[num].score[i];

	if (isMarsOk(array[num].score, Constants::scoreRate1 + Constants::scoreRate2))
		return;
	else
	{
		cout << "�� ����� �������� ������, ������� ������ ��� ���: ";
		getScoreRate(array, num);
	}
}


void calcKT(Student* array, int num)
{
	double sumScoreRate1{ 0.0 };
	double sumScoreRate2{ 0.0 };

	// ������ 1-�� ��
	for (int i{ 0 }; i < Constants::scoreRate1; i++) 
	{
		sumScoreRate1 += (array[num].score[i] / static_cast<double>(Constants::maxMark));
	}

	double KT1 = (Constants::maxMarkKT / Constants::scoreRate1) * sumScoreRate1;


	// ������ 2-�� ��
	for (int i{Constants::scoreRate1}; i < (Constants::scoreRate2) * 2; i++)
	{
		sumScoreRate2 += (array[num].score[i] / static_cast<double>(Constants::maxMark));
	}

	double KT2 = (Constants::maxMarkKT / Constants::scoreRate2) * sumScoreRate2;


	// ������ �����
	int allKT = 0;

	allKT = ((KT1 + KT2) / (Constants::maxMarkKT + Constants::maxMarkKT)) * Constants::maxMarkAllKT;



	array[num].KT1 = KT1;	 // ������� ���� �� �� � ���� � ��������� ��������
	array[num].KT2 = KT2;	 //
	array[num].allKT = allKT;//
}


void Auto(Student* array, int num) // ����� ������� ��� ���
{
	if (array[num].allKT >= 50)
	{
		array[num].Auto = true;
	}
}


bool isMarsOk(int* marks, int size) // ������� ��� �������� ��������� ������
{
	for (int i{ 0 }; i < size; ++i)
		if (marks[i] < 0 || marks[i] > Constants::maxMark) // ���� ������ ������ 0 ��� ������ 5, ��
			return false;
	
	return true;
}