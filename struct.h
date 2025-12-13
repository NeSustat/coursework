#pragma once 

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <QFontMetrics>
#include <QFont>

// класс отвечающий за облако слов
class WordCloud {
protected:
    std::vector<std::string> words;
    std::vector<std::vector<bool>> freePlace;
    int len;
public:
    // конструктор. собирает вектор со словами разделяя их по пробелу
    WordCloud();
    bool checkPlace(int x, int y, std::string& word, const QFont font);
    void switchFlagFreePlace(int x, int y, const std::string& word, const QFont& font);
    QSize getSize(const std::string& word, const QFont& font);
    void drawFirstWord();
    void drawWord();
};