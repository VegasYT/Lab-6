#ifndef FUNCS_H
#define FUNCS_H

#include <string>
#include <vector>


namespace Constants
{
	inline constexpr int numStud{3};		// Число студентов в группе
	inline constexpr int scoreRate1{4};		// Число оценок в 1-ой КТ
	inline constexpr int scoreRate2{4};		// Число оценок во 2-ой КТ
	inline constexpr int maxMark{5};		// Макс оценка за работу
	inline constexpr int maxMarkKT{100};	// Макс оценка за КТ
	inline constexpr int maxMarkAllKT{100}; // Макс оценка за Итог
};


struct Student
{
	std::string fio;                                          // Фио студента
	int id;													  // Номер студента
	int score[Constants::scoreRate1 + Constants::scoreRate2]; // Оценки студента
	int KT1;												  // Ну тут и так все ясно
	int KT2;												  // Ну тут и так все ясно
	int allKT;											      // Ну тут тоже вроде все ясно
	bool Auto = false;										  // Мечта любого студента
};


void getGroup(Student* array);
void getScoreRate(Student* array, int num);
bool isMarsOk(int* marks, int size);
void calcKT(Student* array, int num);
void Auto(Student* array, int num);

#endif
