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
using std::ostream;
using std::istream;

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
        friend ostream& operator << (ostream &out, const Watch &w);
        friend istream& operator >> (istream& in, Watch& w);
    } created_by;
    string type;
public:
    Watch();
    Watch(const string name, const string water, const int price, const string firma, const string country,const string type);
    Watch(const Watch &p);
    Watch(string Name);
    void operator = (const Watch& other);
    bool operator == (const Watch& other);
    bool operator != (const Watch& other);
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
    friend ostream& operator << (ostream &out, const Watch &w);
    friend istream& operator >> (istream& in, Watch& w);    
};
ostream& operator << (ostream &out, const Watch &w);
istream& operator >> (istream& in, Watch& w);