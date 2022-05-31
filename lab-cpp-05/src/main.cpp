/**
 * @mainpage
 * # Загальне завдання
 * Переробити програми, що були розроблені під час виконання лабораторних робіт з тем
 * “Масиви” та “Цикли” таким чином, щоб використовувалися функції для обчислення результату.
 * Функції повинні задовольняти основну їх причетність - уникати дублювання коду. Тому,
 * для демонстрації роботи, ваша програма (функція main()) повинна мати можливість викликати
 * розроблену функцію з різними вхідними даними.
 *
 * @file main.c
 * @brief Файл з основним кодом.
 *
 * @author Pustovyi I.
 * @date 10-may-2022
 * @version 1.0
 */
#include "list.hpp"
int main() {
    List<int> list;
    list.add(14);
    list.add(1);
    list.add(2);
    list.add(236);
  //  list.print();
    std::cout << std::endl;
    list.add(15);
    list.print();
    std::cout << std::endl;
    //list.findbyindex(20);
    //std::cout << list.findbyindex(0);
    list.sort();
    list.print();
    int x = list.min();
    std::cout << x << std::endl; 

    return 0;
}