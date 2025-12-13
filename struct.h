#pragma once 

#include <vector>
#include <cmath>
#include <string>
#include <iostream>

// класс отвечающий за облако слов
class WordCloud {
protected:
    std::vector<std::string> words;
public:
    // конструктор. собирает вектор со словами разделяя их по пробелу
    WordCloud();
};