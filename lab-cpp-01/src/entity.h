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
#define Size 100
/**
 * @brief Basic class
 * 
 */
class Watch {
private:
    char name[Size];
    char water[Size];
    int price;
    /**
     * @brief class in class
     * 
     */
    class made_by {
        private:
            char firma[Size];
            char country[Size];
        public:
        /**
         * @brief Get the Firma object
         * 
         * @return char* - firma
         */
        char* getFirma();
        /**
         * @brief Set the Firma object
         * 
         * @param Firma firma
         */
        void setFirma(char *Firma);
        /**
         * @brief Get the Country object
         * 
         * @return char* 
         */
        char* getCountry();
        /**
         * @brief Set the Country object
         * 
         * @param Country 
         */
        void setCountry(char *Country);
        friend class Watch;
        friend class List;
    } created_by;
    char type[Size];
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
    Watch(const char *name,const char *water,const int price,const char *firma,const char *country,const char *type);
    /**
     * @brief Copy object
     * 
     * @param p 
     */
    Watch(const Watch &p);
    /**
     * @brief Destroy the Watch object
     * 
     */
    ~Watch();
    /**
     * @brief Get the Name object
     * 
     * @return char* 
     */
    char* getName();
    /**
     * @brief Set the Name object
     * 
     * @param Name 
     */
    void setName(char *Name);
    /**
     * @brief Get the Water object
     * 
     * @return char* 
     */
    char* getWater();
    /**
     * @brief Set the Water object
     * 
     * @param Water 
     */
    void setWater(char *Water);
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
     * @return char* 
     */
    char* getType();
    /**
     * @brief Set the Type object
     * 
     * @param Type 
     */
    void setType(char *Type);
    /**
     * @brief вивод обєкту
     * 
     */
    void print();
    friend class List;
};