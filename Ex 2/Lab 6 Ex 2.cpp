#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <iterator>
#include <windows.h>


#include "Funcs.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");  // Для корректного отображения русского языка 
    SetConsoleCP(1251);       //
    SetConsoleOutputCP(1251); //

    Student group[Constants::numStud]{}; // Создаем массив с количеством эелементов указанных в Constants::

    cout << "Введите ФИО студента: \n";
    getGroup(group); // Заносим введенные имена в массив
    

    cout << endl;
    for (int i{ 0 }; i < Constants::numStud; i++) // Выполняем до тех пор, пока i меньше числа студентов
        getScoreRate(group, i); // Заносим введенные оценки в массив


    for (int i{ 0 }; i < Constants::numStud; i++) // Считаем и записываем балы за КТ каждого студента
    {
        calcKT(group, i);
        Auto(group, i);
    }

    // Выводим таблицу
    cout << "\nТаблица результатов: \n" << "N\t" << "ФИО\t\t" << "KT-1\t" << "KT-2\t" << "Итог\t" << "Автомат";
    for (int i{ 0 }; i < Constants::numStud; i++)
    {
        cout << boolalpha << "\n" << group[i].id << "\t" << group[i].fio << "\t\t" << group[i].KT1 << "\t" << group[i].KT2 << "\t" << group[i].allKT << "\t" << group[i].Auto;
    }
    cout << endl;
    

    return 0;
}