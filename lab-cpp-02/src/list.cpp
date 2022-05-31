/**
 * @file list.cpp
 * @brief Файл з реалізацією функцій пов'язаних зі структурою базового класу
 *
 * @author Пустовий І. І.
 * @date 18-may-2022
 * @version 1.0
 */
#include "list.h"
void List::print() {
        for(unsigned int i=0; i < size;i++){
            cout<<this->watchlist[i].getName()<<" "<<this->watchlist[i].getWater()<<" "<<this->watchlist[i].getPrice()<<" "<<this->watchlist[i].created_by.getFirma()<<" "<<this->watchlist[i].created_by.getCountry()<<" "<<this->watchlist[i].getType()<<std::endl;
        }
    }
void List::addWatch(Watch *std, size_t pos) {
    Watch *watches = new Watch[size+1];
    if(this->size<pos) {
        pos = this->size;
    };
    memcpy(watches, this->watchlist, pos*sizeof(Watch));
    memcpy(watches+pos, std, sizeof(Watch));
    memcpy(watches+pos+1, this->watchlist+pos, (this->size-pos)*sizeof(Watch));
    //delete[] watchlist;
    this->watchlist = watches;
    this->size++;
    //printf("%s %s %d %s %s %s\n", std->name, std->water, std->price, std->created_by.firma, std->created_by.country, std->type);
}
void List::deletwatch(const unsigned int index) {
    Watch *watches = new Watch[size-1];
    memcpy(watches, watchlist, sizeof(Watch)*index);
    memcpy(watches+index,(watchlist+index+1), sizeof(Watch)*(size-index-1));
    //delete[] watchlist;
    watchlist = watches;
    this->size--;
}
Watch & List::findElementWatch(unsigned int index) {
    if (index>=this->size || index < 0) {
        cout<<"Error"<<std::endl;
        return watchlist[NULL];
    }
    else
    return watchlist[index];
}
void List::find(const int price) {
    for(unsigned int i = 0; i < size; i++) {
        if((watchlist[i].price)<price) {
            cout<<watchlist[i].getName()<<" "<<watchlist[i].getWater()<<watchlist[i].getPrice()<<watchlist[i].created_by.getFirma()<<watchlist[i].created_by.getCountry()<<watchlist[i].getType()<<std::endl;
        }
    }
}
void List::writeToFile(){
    ofstream fout;
    fout.open("/home/xanzik/programming-pustoviy-cpp/lab-cpp-02/assets/output.txt");
    for(unsigned int i = 0; i < this->size; i++) {
        fout << this->watchlist[i].getName()<<" "<<this->watchlist[i].getWater()<<" "<<this->watchlist[i].getPrice()<<" "<<this->watchlist[i].created_by.getFirma()<<" "<<this->watchlist[i].created_by.getCountry()<<" "<<this->watchlist[i].getType()<<std::endl;
    }
    fout.close();
}
void List::readFromFile(){
    this->size = 0;
    this->watchlist = 0;
    string name;
    string water;
    int price;
    string firma;
    string country;
    string type;
    ifstream fout;
    fout.open("/home/xanzik/programming-pustoviy-cpp/lab-cpp-02/assets/input.txt");
    while(!fout.eof()){
        fout >> name >> water >> price >> firma >> country >> type;
        Watch *watches = new Watch(name, water, price, firma, country, type);
        this->addWatch(watches, 0);
    }
    fout.close();
}