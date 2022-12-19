#ifndef FUNCS_H
#define FUNCS_H

#include <string>
#include <vector>


namespace Constants
{
	inline constexpr int numStud{3};		// ����� ��������� � ������
	inline constexpr int scoreRate1{4};		// ����� ������ � 1-�� ��
	inline constexpr int scoreRate2{4};		// ����� ������ �� 2-�� ��
	inline constexpr int maxMark{5};		// ���� ������ �� ������
	inline constexpr int maxMarkKT{100};	// ���� ������ �� ��
	inline constexpr int maxMarkAllKT{100}; // ���� ������ �� ����
};


struct Student
{
	std::string fio;                                          // ��� ��������
	int id;													  // ����� ��������
	int score[Constants::scoreRate1 + Constants::scoreRate2]; // ������ ��������
	int KT1;												  // �� ��� � ��� ��� ����
	int KT2;												  // �� ��� � ��� ��� ����
	int allKT;											      // �� ��� ���� ����� ��� ����
	bool Auto = false;										  // ����� ������ ��������
};


void getGroup(Student* array);
void getScoreRate(Student* array, int num);
bool isMarsOk(int* marks, int size);
void calcKT(Student* array, int num);
void Auto(Student* array, int num);

#endif