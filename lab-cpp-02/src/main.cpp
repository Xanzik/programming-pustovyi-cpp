/**
 * @mainpage
 * # Загальне завдання
 * Поширити попередню лабораторну роботу таким чином:
• використання функцій printf/scanf замінити на використання cin/cout;
• усі конкатенації рядків замінити на використання stringstream;
• замінити метод виводу інформації про об’єкт на метод, що повертає рядок-інформаціюпро об’єкт, який далі можна виводити на екран;std::string& Phone::toString();
• замінити метод вводу інформації про об’єкт на метод, що приймає рядок з інформацієюпро об’єкт, обробляє його та створює об’єкт на базі цієї інформації
• поширити клас-список, шляхом реалізації методів роботи з файлами за допомогоюфайлових потоків (fstream) (якщо використовувалися функції fprintf/fscanf – замінити їх накласи ifsteam/ofstream), при цьому сигнатури методів повинні виглядати таким чином:
* – читання (List – клас-список об’єктів, при цьому слід пам’ятати, що при повторномучитанні з файлу, попередні дані списку повинні бути очищені):void List::readFromFile(std::string& fileName);– запис:void List::writeToFile(std::string& fileName);

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
 * - додаємо часи до списку {@link readFromFile} та {@link addWatch} метод класу {@link List}
 * - записуємо масив до файлу {@link writeToFile} метод класу {@link List}
 * - виводимо на екран {@link print} метод класу {@link List}
 * @return successful return code from the program (0)
 */
int main() {
/*	Watch *Air = new Watch("AirWatch", "Yes", 500, "AirCompany", "UK", "Sport");
    Watch *Fair = new Watch("FairWatch", "No", 300, "FairCompany", "USA", "Style");
    Watch *Microsoft = new Watch("MicrosoftWatch", "Yes", 1300, "Microsoft", "USA", "Sport");
    Watch *Casio = new Watch("Casio", "No", 1500, "Casios", "Poland", "Classic");
    Watch *Rolex = new Watch("Rolex", "No", 3000, "RolexWatch", "Canada", "Classic");*/
    List *list = new List();
    Watch *Por = new Watch;
   /* list->addWatch(Air, 0);
    list->addWatch(Fair, 1);
    list->addWatch(Microsoft, 2);
    list->addWatch(Casio, 3);
    list->addWatch(Rolex, 4);*/
    list->readFromFile();
    list->addWatch(Por, 5);
    cout << std::endl;
    list->writeToFile();
    list->print();
    //list->deletwatch(1);
    //list->print();

    return 0;
}