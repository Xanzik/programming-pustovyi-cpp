/**
 * @mainpage
 * # Загальне завдання
Поширити реалізацію лабораторної роботи “Поліморфірзм” наступним шляхом:
• замінити масив та CRUD (create/read/update/delete) методи роботи з ним на використання
STL
• для предметної галузі з розділу “Розрахункове завдання / Iндивідуальні завдання”
реализувати/оновити всі методи роботи з колекцією на використання функцій STL
• додати функцію сортування коллекції з використанням функтора
• додати функцію об’єднання двох класів-списків

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
 * - Створюєємо список {@vector <Watch> list[10]}
 * - додаємо елементи до списку з файлу за допомогою {@link readFromFile}
 * - виводимо на екран {@link print}
 * - видаляємо обєкт {@link del}
 * - виводимо на екран {@link print}
 * - сортируємо {@link SORT}
 * - виводимо на екран {@link print}
 * @return successful return code from the program (0)
 */

int size = 0;

int main() {
    vector <Watch> list[10];
    readFromFile(*list, size);
    print(*list, size);
    del(*list, size, 1);
    print(*list, size);
    SORT(*list);
    print(*list, size);
    return 0;
}