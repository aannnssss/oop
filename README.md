# Отчёт по лабораторной работе №1 по курсу “Объектно-ориентированное программирование"

<b>Студент группы:</b> <ins>М80-208Б-22 Старостина Анна Андреевна, № по списку 18</ins>

<b>Контакты e-mail:</b> <ins>st4ro5tinaa@yandex.ru</ins>

## 1. Тема
Первая программа на С++
## 2. Цель работы
Изучить систему сборки CMake  
Изучить базовые операторы и конструкции C++  
Изучить библиотеку для написания Unit-тестов Google Test  
Научится писать простые программы, использующие ввод/вывод через потоки std::cin и std::cout  
## 3. Задание (вариант № 19)
Выполните функцию преобразования целого числа в строку с турецким именем числа.
На вход всегда подается целое число 0-99;  
Выходные данные всегда должны быть в нижнем регистре.  
Формирование турецких названий для чисел 0-99 очень просто:  
• единицы (0-9) и десятки (10, 20, 30 и т.д.) имеют свое собственное уникальное имя;  
• все остальные числа обозначаются просто [tens] + [unit], как, например, twenty one в английском языке.  
В турецком языке единицы и десятки называются следующим образом:
0 = sıfır  
1 = bir  
2 = iki  
3 = üç  
4 = dört  
5 = beş  
6 = altı  
7 = yedi  
8 = sekiz  
9 = dokuz  
10 = on  
20 = yirmi  
30 = otuz  
40 = kırk  
50 = elli  
60 = altmış  
70 = yetmiş  
80 = seksen  
90 = doksan
## 4. Код программы
```
#include <iostream>
#include "turkish.hpp"

int main() {

    int n;

    std::cin >> n;
    std::cout << translationIntoTurkish(n) << std::endl;

    return 0;
}
```
```
#pragma once
#include <string>

std::string translationIntoTurkish(int n);
```
```
#include "turkish.hpp"

std::string translationIntoTurkish(int n) {
    int p = n;
    std::string result = "";
    if (p/10!=0) {   
        switch (p/10) {
            case 1: {result = "on"; break;}
            case 2: {result = "yirmi"; break;}
            case 3: {result = "otuz"; break;}
            case 4: {result = "kırk"; break;}
            case 5: {result = "elli"; break;}
            case 6: {result = "altmış"; break;}
            case 7: {result = "yetmiş"; break;}
            case 8: {result = "seksen"; break;}
            case 9: {result = "doksan"; break;}
        }
        p%=10;
        if (p) result +=" ";
    }
    switch (p) {
        case 0: {if (n/10!=0) break; else {result = "sifir"; break;}}
        case 1: {result += "bir"; break;}
        case 2: {result += "iki"; break;}
        case 3: {result += "üç"; break;}
        case 4: {result += "dört"; break;}
        case 5: {result += "beş"; break;}
        case 6: {result += "altı"; break;}
        case 7: {result += "yedi"; break;}
        case 8: {result += "sekiz"; break;}
        case 9: {result += "dokuz"; break;}
    }
    return result;
}
```
## 5. Тесты
```
#include <gtest/gtest.h>
#include "turkish.hpp"

TEST(test1, p) {
    int n = 0;
    ASSERT_TRUE(translationIntoTurkish(n) == "sifir");
}

TEST(test2, p) {
    int n = 1;
    ASSERT_TRUE(translationIntoTurkish(n) == "bir");
}

TEST(test3, p) {
    int n = 40;
    ASSERT_FALSE(translationIntoTurkish(n) == "elli");
}

TEST(test4, p) {
    int n = 70;
    ASSERT_TRUE(translationIntoTurkish(n) == "yetmiş");
}

TEST(test5, p) {
    int n = 13;
    ASSERT_FALSE(translationIntoTurkish(n) == "yirmi yedi");
}

TEST(test6, p) {
    int n = 13;
    ASSERT_TRUE(translationIntoTurkish(n) == "on üç");
}

TEST(test7, p) {
    int n = 94;
    ASSERT_TRUE(translationIntoTurkish(n) == "doksan dört");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
## 6. Распечатка протокола
```
(base) annastarostina@MacBook-Pro-Anna build % cmake --build .
[ 50%] Built target task
[100%] Built target tests
(base) annastarostina@MacBook-Pro-Anna build % cmake --build .
[ 50%] Built target task
[ 66%] Building CXX object CMakeFiles/tests.dir/tests.cpp.o
[ 83%] Linking CXX executable tests
[100%] Built target tests
(base) annastarostina@MacBook-Pro-Anna build % ./tests        
[==========] Running 7 tests from 7 test suites.
[----------] Global test environment set-up.
[----------] 1 test from test1
[ RUN      ] test1.p
[       OK ] test1.p (0 ms)
[----------] 1 test from test1 (0 ms total)

[----------] 1 test from test2
[ RUN      ] test2.p
[       OK ] test2.p (0 ms)
[----------] 1 test from test2 (0 ms total)

[----------] 1 test from test3
[ RUN      ] test3.p
[       OK ] test3.p (0 ms)
[----------] 1 test from test3 (0 ms total)

[----------] 1 test from test4
[ RUN      ] test4.p
[       OK ] test4.p (0 ms)
[----------] 1 test from test4 (0 ms total)

[----------] 1 test from test5
[ RUN      ] test5.p
[       OK ] test5.p (0 ms)
[----------] 1 test from test5 (0 ms total)

[----------] 1 test from test6
[ RUN      ] test6.p
[       OK ] test6.p (0 ms)
[----------] 1 test from test6 (0 ms total)

[----------] 1 test from test7
[ RUN      ] test7.p
[       OK ] test7.p (0 ms)
[----------] 1 test from test7 (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 7 test suites ran. (0 ms total)
[  PASSED  ] 7 tests.
```
## 7. Выводы

Благодаря лабораторной работе, была написана первая лабораторная работа на С++. Язык очень похож на С, так что особых проблем не возникло. Были изучены Google Tests. Так же была изучена работа с cmake, что довольно упрощает работу про комиляции нескольких программ. Так же теперь я знаю, как составляются числа в турецком языке.
