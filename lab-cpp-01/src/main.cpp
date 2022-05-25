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
#include "list.h"
int main() {
	Watch *Air = new Watch("AirWatch", "Yes", 500, "AirCompany", "UK", "Sport");
    Watch *Fair = new Watch("FairWatch", "No", 300, "FairCompany", "USA", "Style");
    Watch *Microsoft = new Watch("MicrosoftWatch", "Yes", 1300, "Microsoft", "USA", "Sport");
    Watch *Casio = new Watch("Casio", "No", 1500, "Casios", "Poland", "Classic");
    Watch *Rolex = new Watch("Rolex", "No", 3000, "RolexWatch", "Canada", "Classic");
    List *list = new List();
    list->addWatch(Air, 0);
    list->addWatch(Fair, 1);
    list->addWatch(Microsoft, 2);
    list->addWatch(Casio, 3);
    list->addWatch(Rolex, 4);
    list->print();
    list->deletwatch(3);
    list->print();

    return 0;
}