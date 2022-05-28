#include "entity.h"

class List {
private:
    size_t size;
    Watch *watchlist;
public:
    void addWatch(Watch *std, size_t pos);
    void print();
    Watch& findElementWatch(unsigned int index);
    void deletwatch(const unsigned int index);
    void find(const int price);
    void writeToFile();
    void readFromFile();
    Watch& operator[] (const int index);
    friend ofstream& operator <<(ofstream &out,const List &list);
    friend ifstream& operator >>(ifstream &in, List &list);
    size_t getSize();
};
ofstream& operator <<(ofstream &out,const List &list);
ifstream& operator >>(ifstream &in, List &list);