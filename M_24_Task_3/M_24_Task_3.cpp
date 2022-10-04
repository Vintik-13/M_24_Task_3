/*Задание 3. Реализация программы таймера
* 
Что нужно сделать
Реализуйте работу точного таймера с визуальной отдачей.
В начале программы пользователь вводит количество минут
и секунд, которые требуется засечь на таймере, и нажимает
«Ввод».
После этого начинается обратный отсчёт времени, о чём
незамедлительно и последовательно сообщается пользователю.
Формат вывода такой же, как и при вводе интервала: минуты
и секунды.
Как только отсчёт на таймере иссяк, программа сообщает об этом
с помощью вывода в консоль специального сообщения. Сообщение
вместо аудиосигнала может выглядеть так: DING! DING! DING!*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <iomanip>
#include <Windows.h>

int sec(int min, int sec) {
    return min * 60 + sec;
}

int main()
{
    std::time_t ti1 = std::time(nullptr);
    std::tm t1{};

    std::cout << "Enter the timer time: ";
    std::cin >> std::get_time(&t1, "%M:%S");
    std::tm* t2 = std::localtime(&ti1);
    t2->tm_min = t1.tm_min;
    t2->tm_sec = t1.tm_sec;
   
    for (int i = 0; i < sec(t1.tm_min, t1.tm_sec); i++) {
        std::cout << std::put_time(t2, "%M:%S") << std::endl;
        std::time_t tmp = std::mktime(t2);
        tmp--;
        t2 = std::localtime(&tmp);
        Sleep(1000);
        system("cls");

    }
    std::cout << "DING! DING! DING!";
}

