# Лабораторна робота №21. ООП. Шаблонні функції та класи

## Вимоги

### 1.1 Розробник

* Пустовий І. І.
* студент групи КН-921в;
* 18-may-2022.

### 1.2 Загальне завдання

 Зробити шаблоний клас-список (на базі динамічного масиву), що має шаблоноване поле
масиву (для будь-якого існуючого типу даних)
• Створити наступні методи:
– вивод вмісту масиву на екран;
– визначити індекс переданого елемента в заданому масиві;
– відсортувати елементи масиву;
– визначити значення мінімального елемента масиву;
– додати елемент до кінця масиву;
– видалити елемент з масиву за індексом.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для роботи з ООП.

Для вхідних даних діють такі *обмеження*:
 - для кількості полів структури: 5;
 

### 2.2 Опис логічної структури

За допомогою ключового слова class описуємо дисципліну, що має 5 полів – назву, водопроніційність, ціна, фірма та країна, тип.

За допомогою ключового слова class описуємо список, що має 2 поля – вказівник на масив об'єктів типу Watch та кількість об'єктів у цьому масиві.

#### 2.2.1 Функція виводу класу List на екран

```c
	void print()
```

*Призначення*: Виведення на екран полів класу.
*Опис роботи*: вивод на екран елементи через цикли.

#### 2.2.2 Функція знаходження мінімального елементу

```c
T List<T>::min()
```
*Призначення*: повертає мінімальний елемент.
*Опис роботи*: сортируємо масив і повертаємо нульовий елемент.

#### 2.2.3 Функція звернення до об'єкта за індексом

```c
    T& findbyindex(const unsigned int index);
```

*Призначення*: Звернення до об'єкта за індексом.

#### 2.2.4 Функція сортіровки

```c
    void sort();
```

*Призначення*: сортіровка.
*Опис роботи*: Сортіровка бульбашкою.

#### 2.2.5 Функція додавання об'єкта за індексом

```c
    void add(const T& element);
```

*Призначення*: Додавання об'єкта за  до масиву списку.

#### 2.2.6 Функція видаленя об'єкта за індексом

```c
    void delet(const unsigned int index);
```

*Призначення*: Видалення об'єкта з масиву за індексом.
*Опис роботи*: Копіюємо данні праворуч та ліворуч від індексу, який ми передаєио, видалення поля з масивом та занесення туди сгенерований у функції масив.

#### 2.2.7 Основна функція

```c
	int main()
```

*Призначення*: Головна функція.
*Опис роботи*: 
 * - Створюєємо список {@link List<int> list}
 * - додаємо елементи до списку за допомогою {@link add}
 * - сортируємо {@link sort} метод класу {@link List}
 * - виводимо на екран {@link print} метод класу {@link List}
 * - створюємо змінну та використовуємо її для знаходження мінімального елементу завдяки функції [@link min]

#### 2.2.4 Структура проекту

```
└── lab-cpp-05
├── Doxyfile
├── Makefile
├── README.md
├── doc
│ └── lab-cpp-05.md
├── test
│ └── test.cpp
└── src
├── list.hpp
└── main.cpp
```

### 2.3 Важливі фрагменти програми

#### 2.3.1 Клас список

```c
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
```
#### 2.3.2 Реалізація сортіровки
```c
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
```
#### 2.3.3 Реалізація поіску по індексу
```c
T& List<T>::findbyindex(const unsigned int index) {
    if(index>=size || index<0){
        std::cout<<"Segmentation Failed";
        return arr[NULL];
    }
    else {
        return arr[index];
    }
}
```
#### 2.3.4 Реалізація видалення елементу за індексом
```c
void List<T>::delet(const unsigned int index) {
    T *el = new T[size-1];
    memcpy(el, arr, sizeof(T)*index);
    memcpy(el + index, (arr+index+1), sizeof(T)*(size-index-1));
    delete[] arr;
    arr = el;
    size--;
}
```
#### 2.3.5 Реалізація функціїї виводу
```c
void List<T>::print() {
    for (unsigned int i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << std::endl;
    }
}
```
#### 2.3.6 Реалізація функції додавання до списку
```c
void List<T>::add(const T& element) {
    T *el = new T[this->size+1];
    memcpy(el, arr, sizeof(T)*size);
    delete[] arr;
    arr = el;
    memcpy(arr+size, &element, sizeof(T));
    size++;
}
```

## 3 Варіанти використання

Для демонстрації результатів кожної задачі використовується:

- покрокове виконання програми в утиліті lldb;
- видача результатів у консоль за допомогою функції виводу.

**Варіант використання**: послідовність дій для запуску програми:
- запустити програму;
- подивитись результати виконання програми

```
rm -rf dist
mkdir dist
clang++ -std=gnu++98 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src src/main.cpp -o ./dist/main.bin
clang++ -std=gnu++98 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src test/test.cpp  -fprofile-instr-generate -fcoverage-mapping -o ./dist/test.bin -lcheck -lm -lrt -lpthread -lsubunit
./dist/main.bin
1
2
14
15
236
1
```

## Висновки

	При виконанні лабораторної роботи були набуті практичні навички роботи з шаблонними функціями та классами.
