/**
 * @file list.hpp
 * @brief Файл з класами та їх функціями
 *
 * @author Пустовий І. І.
 * @date 18-may-2022
 * @version 1.0
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#define SIZE 50
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::ostream;
using std::istream;
/**
 * @brief class of object
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
            friend class Watch;
            friend ostream& operator << (ostream &out, const Watch &w);
    } created_by;
    string type;
public:
/**
 * @brief Construct a new Watch object
 * 
 * @param name 
 * @param water 
 * @param price 
 * @param firma 
 * @param country 
 * @param type 
 */
    Watch(const string name,const string water,const int price,const string firma,const string country,const string type){
        this->name = name;
        this->water = water;
        this->price = price;
        this->created_by.firma = firma;
        this->created_by.country = country;
        this->type = type;
    }
    friend ostream& operator << (ostream &out, const Watch &w);
    friend class sorting;
};
/**
 * @brief Functor
 * 
 */
class sorting{
    public:
    bool operator()(const Watch w, const Watch v){
        return w.price<v.price;
    }
};
/**
 * @brief Sorting function
 * 
 * @param list our list
 */
void SORT(vector<Watch> &list){
    sort(list.begin(), list.end(), sorting());
}
/**
 * @brief add object
 * 
 * @param list 
 * @param size 
 */
void addWatch(vector<Watch> &list, int &size) {
    string name;
    string water;
    int price;
    string firma;
    string country;
    string type;
    cin >> name >> water >> price >> firma >> country >> type;
    list.push_back(Watch(name, water, price, firma, country, type));
    size++;
}
/**
 * @brief reading from file
 * 
 * @param list 
 * @param size 
 */
void readFromFile(vector<Watch> &list, int &size){
    string name;
    string water;
    int price;
    string firma;
    string country;
    string type;
    ifstream file;
    file.open("/home/xanzik/programming-pustoviy-cpp/lab-cpp-06/assets/input.txt");
    if(file.is_open()){
        while(!file.eof()){
            file >> name >> water >> price >> firma >> country >> type;
            Watch *watches = new Watch(name, water, price, firma, country, type);
            list.push_back(*watches);
            size++;
        }
        file.close();
    }
    else{
        cout << "Error of opening file";
    }
}
/**
 * @brief operator << overload
 * 
 * @param os 
 * @param w 
 * @return ostream& 
 */
ostream& operator << (ostream &os, const Watch &w) {
    os << w.name << " " << w.water << " " << w.price << "$" << " " << w.created_by.firma<< " " << w.created_by.country<< " " << w.type << std::endl;
    return os;
}
/**
 * @brief print list
 * 
 * @param list 
 * @param size 
 */
void print(vector<Watch> &list, const int &size){
    for(unsigned long int i = 0; i<(unsigned long)size; i++){
        cout << list.at(i);
    }
}
/**
 * @brief delet object
 * 
 * @param list 
 * @param size 
 * @param index 
 */
void del(vector<Watch> &list, int &size, size_t index){
    list.erase(list.begin() + (long)index);
    size--;
}
