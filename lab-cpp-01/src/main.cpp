/**
 * @mainpage
 * # Загальне завдання
 * Для предметної галузі з розділу “Розрахункове завдання / Iндивідуальні завдання” **розробити два класи**
 *
 *
 * @author Pustoviy I. I.
 * @date 18-may-2022
 * @version 1.0
 */

/**
 * @file main.cpp
 * @brief Файл для ініціалізації та виклику фукцій
 *
 * @author Pustoviy I. I.
 * @date 18-may-2022
 * @version 1.0
 */
#include "list.h"
/**
 * @brief main function
 * - Створюєємо обєкти годинників та список за допомогою конструктора
 * - додаємо часи до списку {@link addWatch} метод класу {@link List}
 * - удаляємо обєкт {@link deletewatch} метод класу {@link List}
 * - шукаємо обєкт {@link find} метод класу {@link  List}
 * - виводимо загальний список обєктів {@link print} метод класу {@link List}
 * @return successful return code from the program (0)
 */
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
    list->deletwatch(3);
    list->find(600);
    list->print();

    return 0;
}