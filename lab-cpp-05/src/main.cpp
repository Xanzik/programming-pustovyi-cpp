/**
 * @mainpage
 * # Загальне завдання
 Зробити шаблоний клас-список (на базі динамічного масиву), що має шаблоноване поле
масиву (для будь-якого існуючого типу даних)
• Створити наступні методи:
– вивод вмісту масиву на екран;
– визначити індекс переданого елемента в заданому масиві;
– відсортувати елементи масиву;
– визначити значення мінімального елемента масиву;
– додати елемент до кінця масиву;
– видалити елемент з масиву за індексом.

 *
 * @file main.cpp
 * @brief Файл з основним кодом.
 *
 * @author Pustovyi I.
 * @date 10-may-2022
 * @version 1.0
 */
#include "list.hpp"
/**
 * @brief main function
 * - Створюєємо список {@link List<int> list}
 * - додаємо елементи до списку за допомогою {@link add}
 * - сортируємо {@link sort} метод класу {@link List}
 * - виводимо на екран {@link print} метод класу {@link List}
 * - створюємо змінну та використовуємо її для знаходження мінімального елементу завдяки функції [@link min]
 * @return successful return code from the program (0)
 */
int main() {
    List<double> list;
    list.add(14);
    list.add(1);
    list.add(2);
    list.add(236);
    list.add(15);
    //list.findbyindex(20);
    //std::cout << list.findbyindex(0);
    list.sort();
    list.print();
    int x = list.min();
    std::cout << x << std::endl; 

    return 0;
}