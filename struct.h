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
    std::vector<std::string> words; // вектор слов
    std::vector<std::vector<bool>> freePlace; // матрица булевых значений чтобы слова не накладывались друг на друга
    QFont font;

    int sideCercle;
public:
    WordCloud(); // конструктор. собирает вектор со словами разделяя их по пробелу
    bool checkPlace(int x, int y, std::string& word, const QFont font); // проверяет свободно ли место для слова
    void switchFlag(int x, int y, const std::string& word, const QFont& font); // поменять в матрице свободные места на занятые после того как будет размещено слово
    QSize getSize(const std::string& word, const QFont& font); // проверка сколько слово пикселей в длину и ширину (надо для поиска центра)
    void drawFirstWord(); // отрисовка первого слова, которое будет самым большим и по центру
    void drawWord(); // спиральная отрисовка всех слов
};