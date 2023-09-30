#include "DateInfo.h"

int main() {
    int m, d, y;
    char buf[80];

    // Создаем объект DateInfo и инициализируем его произвольной датой (например, 9 января 2023 года).
    DateInfo date(1, 9, 2023);

    // Получаем дату и выводим ее на экран.
    date.GetDate(m, d, y);
    std::cout << "Date: " << m << "-" << d << "-" << y << std::endl;

    // Получаем строку с датой и выводим ее на экран.
    date.GetStringDate(buf);
    std::cout << "String Date: " << buf << std::endl;

    // Получаем имя текущего месяца и выводим его на экран.
    date.GetMonth(buf);
    std::cout << "Month: " << buf << std::endl;

    return 0;
}