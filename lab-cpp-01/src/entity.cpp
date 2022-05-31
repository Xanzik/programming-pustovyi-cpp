/**
 * @file entity.cpp
 * @brief Файл з реалізацією функцій пов'язаних зі структурою "Список"
 *
 * @author Пустовий І. І.
 * @date 18-may-2022
 * @version 1.0
 */
#include "entity.h"

Watch::Watch() {
}
Watch::Watch(const char *name,const char *water,const int price,const char *firma,const char *country,const char *type) {
    strcpy(this->name, name);
    strcpy(this->water, water);
    this->price = price;
    strcpy(this->created_by.firma, firma);
    strcpy(this->created_by.country, country);
    strcpy(this->type, type);
}
Watch::Watch(const Watch &p) {
    strcpy(this->name, p.name);
    strcpy(this->water, p.water);
    this->price = p.price;
    strcpy(this->created_by.firma, p.created_by.firma);
    strcpy(this->created_by.country, p.created_by.country);
    strcpy(this->type, p.type);
}
Watch::~Watch() {   
}
char* Watch::getName() {
    return name;
}
void Watch::setName(char *Name) {
    strcpy(this->name, Name);
}
char* Watch::getWater() {
    return water;
}
void Watch::setWater(char *Water) {
    strcpy(this->water, Water);
}
int Watch::getPrice() {
    return price;
}
void Watch::setPrice(int Price) {
    this->price = Price;
}
char* Watch::made_by::getFirma() {
    return firma;
}
void Watch::made_by::setFirma(char *Firma) {
    strcpy(this->firma, Firma);
}
char* Watch::made_by::getCountry() {
    return country;
}
void Watch::made_by::setCountry(char *Country) {
    strcpy(this->country, Country);
}
char* Watch::getType() {
    return type;
}
void Watch::setType(char *Type) {
    strcpy(this->type, Type);
}
void Watch::print() {
    printf("%s %s %d %s %s %s", this->name, this->water, this->price, this->created_by.firma, this->created_by.country, this->type);
}