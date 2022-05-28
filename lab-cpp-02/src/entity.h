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

class Watch {
private:
    string name;
    string water;
    int price;
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
    Watch();
    Watch(const string name, const string water, const int price, const string firma, const string country,const string type);
    Watch(const Watch &p);
    Watch(string Name);
    ~Watch();
    string getName();
    void setName(string Name);
    string getWater();
    void setWater(string Water);
    int getPrice();
    void setPrice(int Price);
    string getType();
    void setType(string Type);
    string& toString();
    friend class List;
};