#include <iostream>
#include <cstring>


template <class T>
class List {
private:
    size_t size;
    T *arr;
public:
    void print();
    void add(const T& element);
    void delet(const unsigned int index);
    T& findbyindex(const unsigned int index);
    void sort();
    T min();
};
template <class T>
T List<T>::min() {
    sort();
    T a = arr[0];
    return a;
}
template <class T>
void List<T>::sort() {
    for(unsigned int i = 0; i<size-1; i++) {
        for(unsigned long int j = 0; j < size - i - 1; j++) {
            if(arr[j]>arr[j+1]) {
                T x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = x;
            }
        }
    }
}
template <class T>
T& List<T>::findbyindex(const unsigned int index) {
    if(index>=size || index<0){
        std::cout<<"Segmentation Failed";
        return arr[NULL];
    }
    else {
        return arr[index];
    }
}
template <class T>
void List<T>::delet(const unsigned int index) {
    T *el = new T[size-1];
    memcpy(el, arr, sizeof(T)*index);
    memcpy(el + index, (arr+index+1), sizeof(T)*(size-index-1));
    delete[] arr;
    arr = el;
    size--;
}
template <class T>
void List<T>::print() {
    for (unsigned int i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << std::endl;
    }
}
template <class T>
void List<T>::add(const T& element) {
    T *el = new T[this->size+1];
    memcpy(el, arr, sizeof(T)*size);
    delete[] arr;
    arr = el;
    memcpy(arr+size, &element, sizeof(T));
    size++;
}