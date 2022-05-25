#include <cstring>
#include <cstdio>
#include <cstdlib>
#define Size 100
class Watch {
private:
    char name[Size];
    char water[Size];
    int price;
    class made_by {
        private:
            char firma[Size];
            char country[Size];
        public:
        char* getFirma();
        void setFirma(char *Firma);
        char* getCountry();
        void setCountry(char *Country);
        friend class Watch;
        friend class List;
    } created_by;
    char type[Size];
public:
    Watch();
    Watch(const char *name,const char *water,const int price,const char *firma,const char *country,const char *type);
    Watch(const Watch &p);
    ~Watch();
    char* getName();
    void setName(char *Name);
    char* getWater();
    void setWater(char *Water);
    int getPrice();
    void setPrice(int Price);
    char* getType();
    void setType(char *Type);
    void print();
    friend class List;
};