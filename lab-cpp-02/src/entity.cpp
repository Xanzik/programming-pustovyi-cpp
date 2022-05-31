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
    cin>>this->name>>this->water>>this->price>>this->created_by.firma>>this->created_by.country>>this->type;
}
Watch::Watch(const string name,const string water,const int price,const string firma,const string country,const string type){
    this->name = name;
    this->water = water;
    this->price = price;
    this->created_by.firma = firma;
    this->created_by.country = country;
    this->type = type;
}
Watch::Watch(const Watch &p) {
    this->name = p.name;
    this->water = p.water;
    this->price = p.price;
    this->created_by.firma = p.created_by.firma;
    this->created_by.country = p.created_by.country;
    this->type = p.type;
}
Watch::~Watch() {   
}
string Watch::getName() {
    return name;
}
void Watch::setName(string Name) {
    this->name = Name;
}
string Watch::getWater() {
    return water;
}
void Watch::setWater(string Water) {
    this->water = Water;
}
int Watch::getPrice() {
    return price;
}
void Watch::setPrice(int Price) {
    this->price = Price;
}
string Watch::made_by::getFirma() {
    return firma;
}
void Watch::made_by::setFirma(string Firma) {
    this->firma = Firma;
}
string Watch::made_by::getCountry() {
    return country;
}
void Watch::made_by::setCountry(string Country) {
    this->country = Country;
}
string Watch::getType() {
    return type;
}
void Watch::setType(string Type) {
    this->type = Type;
}
string& Watch::toString() {
    //cout<<this->name<<" "<<this->water<<this->price<<this->created_by.firma<<this->created_by.country<<this->type<<std::endl;
    stringstream ss;
    string *s = new string;
    ss << getName() << getWater() << getPrice() << created_by.getFirma() << created_by.getCountry() << getType() << std::endl;
    *s = ss.str();
    cout << *s;
    delete s;
    return *s;
}
