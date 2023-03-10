#include <iostream>
#include <limits>

using namespace std;


int money[7][10]; // Первое значение - номер дня недели, второе - номер расхода 
int coins[7]; // Расходы каждого дня

int zap(int numday)
{
    for (int i = 0; i < 10; i++) 
    {
        cin >> money[numday][i]; // Заполняем заданный день недели

        if (money[numday][i] == 0) // Если пользователь ввел 0, то выходим с функции
            break;
    }

    return 0;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int all{ 0 }, max{ 0 }, avrg{0}, sum{ 0 }, min = numeric_limits<int>::max();
    string daymin = "--", daymax;

    cout << "Введите расходы за каждый из дней через пробел (максимум 10). Если расходов больше нет, введите 0: ";
    cout << "\n\nПонедельник: ";
    zap(0);
    cout << "Вторник: ";
    zap(1);
    cout << "Среда: ";
    zap(2);
    cout << "Четверг: ";
    zap(3);
    cout << "Пятница: ";
    zap(4);
    cout << "Суббота: ";
    zap(5);
    cout << "Воскресенье: ";
    zap(6);


    for (int a{ 0 }; a < 7; a++)
    {
        for (int i{ 0 }; i < 10; i++)
        {
            coins[a] += money[a][i]; // Расходы каждого дня
            all += money[a][i];      // Расходы за всю неделю
        }


        if (coins[a] < min) // Минимальный расход за день
            min = coins[a];

        if (coins[a] > max) // Максимальный расход за день
            max = coins[a];

        sum += coins[a]; // Сумма всех расходов (для среднего расхода за день)
    }

    if (min == coins[0])
        daymin = " Понедельник ";
    else if (min == coins[1])
        daymin = " Вторник ";
    else if (min == coins[2])
        daymin = " Среда ";
    else if (min == coins[3])
        daymin = " Четверг ";
    else if (min == coins[4])
        daymin = " Пятница ";
    else if (min == coins[5])
        daymin = " Суббота ";
    else if (min == coins[6])
        daymin = " Воскресение ";


    if (max == coins[0])
        daymax = " Понедельник ";
    else if (max == coins[1])
        daymax = " Вторник ";
    else if (max == coins[2])
        daymax = " Среда ";
    else if (max == coins[3])
        daymax = " Четверг ";
    else if (max == coins[4])
        daymax = " Пятница ";
    else if (max == coins[5])
        daymax = " Суббота ";
    else if (max == coins[6])
        daymax = " Воскресение ";



    cout << "\nАнализ расходов: \n";
    cout << "Общие расходы за неделю: " << all << endl;
    cout << "День с минимальным расходами:" << daymin << endl;
    cout << "День с максимальными расходами:" << daymax << endl;
    cout << "Средние расходы за 1 день: " << (double)sum / 7 << endl;
}
