#include <iostream>
#include "Funcs.h"

using namespace std;


void getGroup(Student* array) // Функция для заполнения ФИО студента
{
	for (int i{ 0 }; i < Constants::numStud; ++i)
	{
		array[i].id = i + 1;
		cout << "студент N" << array[i].id << ": ";
		getline(cin >> ws, array[i].fio);
	}
}


void getScoreRate(Student* array, int num) // Функция для получения оценок студента
{
	if (num < 0 || num > Constants::numStud - 1) 
		return;

	cout << "Оценки студента " << array[num].fio << ": ";
	for (int i{0}; i < Constants::scoreRate1 + Constants::scoreRate2; i++)
		cin >> array[num].score[i];

	if (isMarsOk(array[num].score, Constants::scoreRate1 + Constants::scoreRate2))
		return;
	else
	{
		cout << "Вы ввели неверную оценку, введите оценки еще раз: ";
		getScoreRate(array, num);
	}
}


void calcKT(Student* array, int num)
{
	double sumScoreRate1{ 0.0 };
	double sumScoreRate2{ 0.0 };

	// Расчет 1-ой КТ
	for (int i{ 0 }; i < Constants::scoreRate1; i++) 
	{
		sumScoreRate1 += (array[num].score[i] / static_cast<double>(Constants::maxMark));
	}

	double KT1 = (Constants::maxMarkKT / Constants::scoreRate1) * sumScoreRate1;


	// Расчет 2-ой КТ
	for (int i{Constants::scoreRate1}; i < (Constants::scoreRate2) * 2; i++)
	{
		sumScoreRate2 += (array[num].score[i] / static_cast<double>(Constants::maxMark));
	}

	double KT2 = (Constants::maxMarkKT / Constants::scoreRate2) * sumScoreRate2;


	// Расчет итога
	int allKT = 0;

	allKT = ((KT1 + KT2) / (Constants::maxMarkKT + Constants::maxMarkKT)) * Constants::maxMarkAllKT;



	array[num].KT1 = KT1;	 // Заносим балы за КТ и Итог в структуру студента
	array[num].KT2 = KT2;	 //
	array[num].allKT = allKT;//
}


void Auto(Student* array, int num) // Будет автомат или нет
{
	if (array[num].allKT >= 50)
	{
		array[num].Auto = true;
	}
}


bool isMarsOk(int* marks, int size) // Функция для проверки введенной оценки
{
	for (int i{ 0 }; i < size; ++i)
		if (marks[i] < 0 || marks[i] > Constants::maxMark) // Если оценка меньше 0 или больше 5, то
			return false;
	
	return true;
}
