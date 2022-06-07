# Лабораторна робота №22. (х2) ООП. STL. Вступ до Стандартної бібліотеки
шаблонів


## Вимоги

### 1.1 Розробник

* Пустовий І. І.
* студент групи КН-921в;
* 18-may-2022.

### 1.2 Загальне завдання

Поширити реалізацію лабораторної роботи “Поліморфірзм” наступним шляхом:
• замінити масив та CRUD (create/read/update/delete) методи роботи з ним на використання
STL
• для предметної галузі з розділу “Розрахункове завдання / Iндивідуальні завдання”
реализувати/оновити всі методи роботи з колекцією на використання функцій STL
• додати функцію сортування коллекції з використанням функтора
• додати функцію об’єднання двох класів-списків

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для роботи з ООП.

Для вхідних даних діють такі *обмеження*:
 - для кількості полів структури: 5;
 

### 2.2 Опис логічної структури

За допомогою ключового слова class описуємо дисципліну, що має 5 полів – назву, водопроніційність, ціна, фірма та країна, тип.

За допомогою ключового слова class описуємо функтор, що має перевантажений оператор.

#### 2.2.1 Функція виводу списку на екран

```c
	void print(vector<Watch> &list, const int &size)
```

*Призначення*: Виведення на екран полів класу.
*Опис роботи*: вивод на екран елементи через цикли.

#### 2.2.2 функція читання з файлу
```c
    void readFromFile(vector<Watch> &list, int &size)
    *Призначення*: Считування обєктів з файлу
    *Опис роботи*: За допомогою функції *cin* считує та записує данні.

```

#### 2.2.3 перевантаження оператору <<
```c
    ofstream& operator <<(ofstream &out,const List &list);
    *Призначення*: запис до файлу.
    *Опис роботи*:  считує та записує данні.
```


#### 2.2.4 Функція сортіровки

```c
    void SORT(vector<Watch> &list)
```

*Призначення*: сортіровка.

#### 2.2.5 Функція додавання об'єкта за індексом

```c
    void addWatch(vector<Watch> &list, int &size)
```

*Призначення*: Додавання об'єкта за  до масиву списку.

#### 2.2.6 Функція видаленя об'єкта за індексом

```c
   void del(vector<Watch> &list, int &size, size_t index)
```

*Призначення*: Видалення об'єкта з масиву за індексом.
*Опис роботи*: Копіюємо данні праворуч та ліворуч від індексу, який ми передаєио, видалення поля з масивом та занесення туди сгенерований у функції масив.

#### 2.2.7 Основна функція

```c
	int main()
```

*Призначення*: Головна функція.
*Опис роботи*: 
 * - Створюєємо список {@vector <Watch> list[10]}
 * - додаємо елементи до списку з файлу за допомогою {@link readFromFile}
 * - виводимо на екран {@link print}
 * - видаляємо обєкт {@link del}
 * - виводимо на екран {@link print}
 * - сортируємо {@link SORT}
 * - виводимо на екран {@link print}

#### 2.2.4 Структура проекту

```
└── lab-cpp-06
├── Doxyfile
├── Makefile
├── README.md
├── doc
│ └── lab-cpp-06.md
├── test
│ └── test.cpp
└── src
├── entity.hpp
├── list.hpp
└── main.cpp
```

### 2.3 Важливі фрагменти програми

#### 2.3.1 Клас обєкту

```c
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
}
```
#### 2.3.2 Реалізація сортіровки
```c
void SORT(vector<Watch> &list){
    sort(list.begin(), list.end(), sorting());
}
```
#### 2.3.3 функція читання з файлу
```c
    void readFromFile();
    *Призначення*: Считування обєктів з файлу
    *Опис роботи*: За допомогою функції *cin* считує та записує данні.

```
#### 2.3.4 Реалізація видалення елементу за індексом
```c
void del(vector<Watch> &list, int &size, size_t index){
    list.erase(list.begin() + (long)index);
    size--;
}

```
#### 2.3.5 Реалізація функціїї виводу
```c
void print(vector<Watch> &list, const int &size){
    for(unsigned long int i = 0; i<(unsigned long)size; i++){
        cout << list.at(i);
    }
}
```
#### 2.3.6 Реалізація функції додавання до списку
```c
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
```
#### 2.3.7 перевантаження оператору <<
```c
    ofstream& operator <<(ofstream &out,const List &list);
    *Призначення*: запис до файлу.
    *Опис роботи*:  считує та записує данні.
```

## 3 Варіанти використання

Для демонстрації результатів кожної задачі використовується:

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
Applewatch Yes 300$ Apple USA Sport
Microsoftwatch Yes 5500$ Microsoft UK Sport
Rolex No 399$ RolexCompany Ukraine Fashion
Applewatch Yes 300$ Apple USA Sport
Rolex No 399$ RolexCompany Ukraine Fashion
Applewatch Yes 300$ Apple USA Sport
Rolex No 399$ RolexCompany Ukraine Fashion

```
## Висновки

	При виконанні лабораторної роботи були набуті практичні навички роботи з стандартною бібліотекою шаблонів.