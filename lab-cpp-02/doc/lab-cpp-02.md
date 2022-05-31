# Лабораторна робота №18. ООП. Потоки

## Вимоги

### 1.1 Розробник

* Пустовий І. І.
* студент групи КН-921в;
* 18-may-2022.

### 1.2 Загальне завдання

Поширити попередню лабораторну роботу таким чином:
• використання функцій printf/scanf замінити на використання cin/cout;
• усі конкатенації рядків замінити на використання stringstream;
• замінити метод виводу інформації про об’єкт на метод, що повертає рядок-інформацію
про об’єкт, який далі можна виводити на екран;
std::string& Phone::toString();
• замінити метод вводу інформації про об’єкт на метод, що приймає рядок з інформацією
про об’єкт, обробляє його та створює об’єкт на базі цієї інформації
• поширити клас-список, шляхом реалізації методів роботи з файлами за допомогою
файлових потоків (fstream) (якщо використовувалися функції fprintf/fscanf – замінити їх на
класи ifsteam/ofstream)

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для знаходження потрібної нам дисципліни за її характеристиками.

Для вхідних даних діють такі *обмеження*:
 - для кількості полів структури: 5;

### 2.2 Опис логічної структури

За допомогою ключового слова class описуємо дисципліну, що має 5 полів – назву, водопроніційність, ціна, фірма та країна, тип.

За допомогою ключового слова class описуємо список, що має 2 поля – вказівник на масив об'єктів типу Watch та кількість об'єктів у цьому масиві.

#### 2.2.1 Функція виводу класу Watch на екран

```c
	void Watch::print()
```

*Призначення*: Виведення на екран полів класу.
*Опис роботи*: За допомогою функції *printf* виводить поля класу.

#### 2.2.2 Функція виводу класу List на екран

```c
	void List::print()
```

*Призначення*: Виведення на екран полів класу.
*Опис роботи*: За допомогою функції *printf* та методу *Subjects::print()* виводить поля класу.

#### 2.2.3 Функція звернення до об'єкта за індексом

```c
    Watch& List::findElementWatch(unsigned int index);
```

*Призначення*: Звернення до об'єкта за індексом.
*Опис роботи*: Якщо pos більше кількості об'єктів, або pos менше нуля, повертає об'єкт з індексом NULL, в іншому випадку повертає об'єкт з індексом pos.

#### 2.2.4 Функція пошуку класу за ціною

```c
    void List::find(const int price);
```

*Призначення*: Пошук потрібної дисципліни за ціною.
*Опис роботи*: Створюємо дві змінні з потрібними нам полями, порівнюємо поля структрури з заданою ціною та виводимо їх на екран.

#### 2.2.5 Функція додавання об'єкта за індексом

```c
        void addWatch(Watch *std, size_t pos);
```

*Призначення*: Додавання об'єкта за індексом до масиву об'єктів.
*Опис роботи*: Копіюємо данні праворуч та ліворуч від індексу, який ми передаєио, копіюємо об'єкт (все у нову змінну, яку ми створюємо у функції), видалення поля з масивом та занесення туди сгенерований у функції масив.

#### 2.2.6 Функція видаленя об'єкта за індексом

```c
    void deletwatch(const unsigned int index);
```

*Призначення*: Видалення об'єкта з масиву за індексом.
*Опис роботи*: Копіюємо данні праворуч та ліворуч від індексу, який ми передаєио, видалення поля з масивом та занесення туди сгенерований у функції масив.

#### 2.2.7 Основна функція

```c
	int main()
```

*Призначення*: Головна функція.
*Опис роботи*: 
 * - Створюєємо обєкти годинників та список за допомогою конструктора
 * - додаємо часи до сиску {@link addWatch} метод класу {@link List}
 * - {@link deletewatch} метод класу {@link deletwatch}
 * - {@link find} метод класу {@link  List}
 * - {@link print} метод класу {@link List}

#### 2.2.8 функція читання з файлу

    void readFromFile();
    *Призначення*: Считування обєктів з файлу
*Опис роботи*: За допомогою функції *cin* считує та записує данні.


#### 2.2.9 функція запису у файл

    void writeToFile();
    *Призначення*: запис до файлу.
*Опис роботи*: За допомогою функції *cout* виводить поля до файлу.

#### 2.2.4 Структура проекту

```
── lab-cpp-02
├── Doxyfile
├── Makefile
├── README.md
├── doc
│ └── lab-cpp-02.md
├── test
│ └── test.cpp
└── src
├── entity.cpp
├── entity.h
├── list.cpp
├── list.h
└── main.cpp
```

### 2.3 Важливі фрагменти програми

#### 2.3.1 Клас список

```c
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
```

#### 2.3.2 Приватні поля базового класу

```c
    char name[Size];
    char water[Size];
    int price;
    class made_by {
        private:
            char firma[Size];
            char country[Size];
	char type[Size];
```

#### 2.3.3 Реалізування пошуку

```c
    for(unsigned int i = 0; i < size; i++) {
        if((watchlist[i].price)<price) {
            cout<<watchlist[i].getName()<<" "<<watchlist[i].getWater()<<watchlist[i].getPrice()<<watchlist[i].created_by.getFirma()<<watchlist[i].created_by.getCountry()<<watchlist[i].getType()<<std::endl;
        }
    }
}
```

#### 2.3.4 Реалізування додавання об'єкту за індексом

```c
    Watch *watches = new Watch[size+1];
    if(this->size>pos) {
        pos = this->size;
    };
    memcpy(watches, this->watchlist, pos*sizeof(Watch));
    memcpy(watches+pos, std, sizeof(Watch));
    memcpy(watches+pos+1, this->watchlist+pos, (this->size-pos)*sizeof(Watch));
    delete[] watchlist;
    this->watchlist = watches;
    this->size++;
```

#### 2.3.5 Реалізування видалення об'єкту за індексом

```c
    Watch *watches = new Watch[size-1];
    memcpy(watches, watchlist, sizeof(Watch)*index);
    memcpy(watches+index,(watchlist+index+1), sizeof(Watch)*(size-index-1));
    delete[] watchlist;
    watchlist = watches;
    this->size--;
```
#### 2.3.6 Реалізування запису до файлу
```c
    ofstream fout;
    fout.open("/home/xanzik/programming-pustoviy-cpp/lab-cpp-02/assets/output.txt");
    for(unsigned int i = 0; i < this->size; i++) {
        fout << this->watchlist[i].getName()<<" "<<this->watchlist[i].getWater()<<" "<<this->watchlist[i].getPrice()<<" "<<this->watchlist[i].created_by.getFirma()<<" "<<this->watchlist[i].created_by.getCountry()<<" "<<this->watchlist[i].getType()<<std::endl;
    }
    fout.close();
```
#### 2.3.7 Реалізування читання з файлу
```c
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
clang++ -std=gnu++98 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src src/entity.cpp src/list.cpp src/main.cpp -o ./dist/main.bin
clang++ -std=gnu++98 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src src/entity.cpp src/list.cpp test/test.cpp  -fprofile-instr-generate -fcoverage-mapping -o ./dist/test.bin -lcheck -lm -lrt -lpthread -lsubunit
./dist/main.bin
Watch Yes 500 Comoany Rwer RArs RR rA s res

Rolex No 399 RolexCompany Ukraine Fashion
Microsoftwatch Yes 5500 Microsoft UK Sport
Applewatch Yes 300 Apple USA Sport
Watch Yes 500 Comoany Rwer RArs
```

## Висновки

	При виконанні лабораторної роботи були набуті практичні навички роботи з потоками.
