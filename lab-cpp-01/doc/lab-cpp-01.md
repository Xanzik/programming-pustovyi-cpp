# Лабораторна робота №17. ООП. Вступ до ООП

## Вимоги

### 1.1 Розробник

* Пустовий І. І.
* студент групи КН-921в;
* 18-may-2022.

### 1.2 Загальне завдання

Для предметної галузі з розділу “Розрахункове завдання / Iндивідуальні завдання” розробити два класи:
* клас, що відображає сутність “базового класу”, у тому числі:
- конструктор за замовчуванням, копіювання та конструктор з аргументами (реалізація конструкторів повинна бути продемонстрована за допомогою списків ініціалізацій);
- деструктор;
- гетери та сетери на поля класу;
- метод виводу об’єкта на екран;
* клас, що має у собі динамічний масив об’єктів базового класу та має в собі методи додавання, видалення елемента, отримання елемента по індексу (або ідентифікатору), вивід усіх елементів на екран.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для знаходження потрібної нам дисципліни за її характеристиками.

Для вхідних даних діють такі *обмеження*:
 - для кількості полів структури: 5;
 
Результат пошуку за критеріями виводиться на екран.

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

#### 2.2.4 Структура проекту

```
── lab-cpp-01
├── Doxyfile
├── Makefile
├── README.md
├── doc
│ └── lab-cpp-01.md
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
            printf("%s\n %s\n %d$\n %s\n %s\n %s\n", watchlist[i].getName(), watchlist[i].getWater(), watchlist[i].getPrice(), watchlist[i].created_by.getFirma(), watchlist[i].created_by.getCountry(), watchlist[i].getType());
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

## 3 Варіанти використання

Для демонстрації результатів кожної задачі використовується:

- покрокове виконання програми в утиліті lldb;
- видача результатів у консоль за допомогою функції виводу.

**Варіант використання**: послідовність дій для запуску програми у режимі відлагодження:
- запустити програму у відлагоднику lldb;
- поставити точку зупинки на функції main (строка з `return 0;`);
- запустити програму;
- подивитись результати виконання програми

```
rm -rf dist
mkdir dist
clang++ -std=gnu++98 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src src/entity.cpp src/list.cpp src/main.cpp -o ./dist/main.bin
clang++ -std=gnu++98 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla -I./src src/entity.cpp src/list.cpp test/test.cpp  -fprofile-instr-generate -fcoverage-mapping -o ./dist/test.bin -lcheck -lm -lrt -lpthread -lsubunit
./dist/main.bin
AirWatch
 Yes
 500$
 AirCompany
 UK
 Sport
FairWatch
 No
 300$
 FairCompany
 USA
 Style
AirWatch Yes 500 AirCompany UK Sport
FairWatch No 300 FairCompany USA Style
MicrosoftWatch Yes 1300 Microsoft USA Sport
Rolex No 3000 RolexWatch Canada Classic
```

## Висновки

	При виконанні лабораторної роботи були набуті практичні навички роботи з класами та методами.
