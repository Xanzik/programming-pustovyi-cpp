/**
 * @file list.h
 * @brief Файл з класом типу "Список" та його методами
 *
 * @author Пустовий І. І.
 * @date 18-may-2022
 * @version 1.0
 */

#include "entity.h"

/**
 * @brief клас Списку
 * 
 */
class List {
private:
    size_t size;
    Watch *watchlist;
public:
/**
 * @brief Функція додання обєкту до списку
 * 
 * @param std обєкт
 * @param pos індекс
 */
    void addWatch(Watch *std, size_t pos);
    /**
     * @brief функція виводу списку
     * 
     */
    void print();
    /**
     * @brief поіск елементу у списці
     * 
     * @param index індекс
     * @return Watch& повертає елемент
     */
    Watch& findElementWatch(unsigned int index);
    /**
     * @brief функція удаління обєкту з списку
     * 
     * @param index індекс
     */
    void deletwatch(const unsigned int index);
    /**
     * @brief функція поіску обєктів нижче вказаної ціни
     * 
     * @param price ціна
     */
    void find(const int price);
    /**
     * @brief Функція запису у файл
     * 
     */
    void writeToFile();
    /**
     * @brief Функція читання з файлу
     * 
     */
    void readFromFile();
    /**
     * @brief operator[]
     * 
     * @param index index
     * @return Watch& 
     */
    Watch& operator[] (const int index);
    friend ofstream& operator <<(ofstream &out,const List &list);
    friend ifstream& operator >>(ifstream &in, List &list);
    /**
     * @brief Get the Size object
     * 
     * @return size_t 
     */
    size_t getSize();
};
/**
 * @brief operator <<
 * 
 * @param out cout
 * @param list out list
 * @return ofstream& 
 */
ofstream& operator <<(ofstream &out,const List &list);
/**
 * @brief operator >>
 * 
 * @param in cin
 * @param list out list
 * @return ifstream& 
 */
ifstream& operator >>(ifstream &in, List &list);