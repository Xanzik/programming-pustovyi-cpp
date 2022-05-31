/**
 * @file entity.h
 * @brief Файл з базовим класом, його методами та списком використовуваних бібліотек
 *
 * @author Пустовий І. І.
 * @date 18-may-2022
 * @version 1.0
 */

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using std::stringstream;
using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
/**
 * @brief Basic Class
 * 
 */
class Watch {
private:
    string name;
    string water;
    int price;
    /**
     * @brief Class in class
     * 
     */
    class made_by {
        private:
            string firma;
            string country;
        public:
        string getFirma();
        void setFirma(string firma);
        string getCountry();
        void setCountry(string country);
        friend class Watch;
        friend class List;
    } created_by;
    string type;
public:
    /**
     * @brief Construct a new Watch object
     * 
     */
    Watch();
    /**
     * @brief Construct a new Watch object
     * 
     * @param name name of watch
     * @param water water
     * @param price price of watch
     * @param firma firma of watch
     * @param country country
     * @param type type
     */
    Watch(const string name, const string water, const int price, const string firma, const string country,const string type);
    /**
     * @brief Construct a new Watch object
     * 
     * @param p 
     */
    Watch(const Watch &p);
    /**
     * @brief Construct a new Watch object
     * 
     * @param Name 
     */
    Watch(string Name);
    /**
     * @brief Destroy the Watch object
     * 
     */
    ~Watch();
    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName();
    /**
     * @brief Set the Name object
     * 
     * @param Name 
     */
    void setName(string Name);
    string getWater();
    /**
     * @brief Set the Water object
     * 
     * @param Water 
     */
    void setWater(string Water);
    /**
     * @brief Get the Price object
     * 
     * @return int 
     */
    int getPrice();
    /**
     * @brief Set the Price object
     * 
     * @param Price 
     */
    void setPrice(int Price);
    /**
     * @brief Get the Type object
     * 
     * @return string 
     */
    string getType();
    /**
     * @brief Set the Type object
     * 
     * @param Type 
     */
    void setType(string Type);
    /**
     * @brief функція яка повертає рядок інформацію про елемент
     * 
     * @return string& 
     */
    string& toString();
    friend class List;
};