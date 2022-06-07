/**
 * @file list.hpp
 * @brief Файл з класом типу "Список" та його методами
 *
 * @author Пустовий І. І.
 * @date 18-may-2022
 * @version 1.0
 */
#include <iostream>
#include <cstring>
/**
 * @brief Робимо список універсальним для різних типів даних
 * 
 * @tparam T 
 */
template <class T>

/**
 * @brief клас список
 * 
 */
class List {
private:
    size_t size;
    T *arr;
public:
    /**
     * @brief print elements
     * 
     */
    void print();
    /**
     * @brief add element by index
     * 
     * @param element 
     */
    void add(const T& element);
    /**
     * @brief delet element by index
     * 
     * @param index 
     */
    void delet(const unsigned T index);
    /**
     * @brief find element
     * 
     * @param index index
     * @return T& 
     */
    T& findbyindex(const unsigned T index);
    /**
     * @brief sorting
     * 
     */
    void sort();
    /**
     * @brief find minimal element
     * 
     * @return T 
     */
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
T& List<T>::findbyindex(const unsigned T index) {
    if(index>=size || index<0){
        std::cout<<"Segmentation Failed";
        return arr[NULL];
    }
    else {
        return arr[index];
    }
}
template <class T>
void List<T>::delet(const unsigned T index) {
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