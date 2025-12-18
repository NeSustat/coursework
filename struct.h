#pragma once 

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <QFontMetrics>
#include <QFont>
#include <QImage>
#include <QPainter>
#include <QString>     
#include <QImage>      
#include <QPainter> 
#include <QPoint>

// класс отвечающий за облако слов
class WordCloud {
protected:
    std::vector<QString> words; // вектор слов
    std::vector<std::vector<bool>> freePlace; // матрица булевых значений чтобы слова не накладывались друг на друга
    QFont font; // шрифт
    QImage image; // создание холста
    QPainter painter; // создание ручки
    std::vector<QColor> color = {
                Qt::red, Qt::blue, Qt::green, Qt::magenta, Qt::cyan,
                Qt::darkRed, Qt::darkBlue, Qt::darkGreen, Qt::darkMagenta, Qt::darkCyan,
                QColor(255, 165, 0),
                QColor(255, 20, 147),
                QColor(75, 0, 130), 
                QColor(255, 69, 0), 
                QColor(50, 205, 50)
    }; // цвета
    int curPixel; // хранит размер текста
    int side; // сторона холста 
    int curIndexWords = 0; // индекс последнего слова + 1
public:
    WordCloud(int side); // конструктор. собирает вектор со словами разделяя их по пробелу
    WordCloud(int side, const std::vector<QString>& testWords); // конструктор для тестов
    void saveImage(); // сохраняет изображение в файл
    virtual bool checkPlace(int x, int y, const QString& word); // проверяет свободно ли место для слова
    void switchFlag(int x, int y, const QString& word); // поменять в матрице свободные места на занятые после того как будет размещено слово
    void drawFirstWord(); // отрисовка первого слова, которое будет самым большим и по центру
    void drawWord(); // спиральная отрисовка всех слов
    void fullDraw(); // заполняет свободные места
    int random(int max); // рандом
    QSize getSize(const QString& word); // проверка сколько слово пикселей в длину и ширину (надо для поиска центра)
    QPoint getLeftTop(int x, int y, const QString& word); // дает верхний левый угол отностилеьно координат центра
    int getSide() const { return side; };
};


class WordCloudCircle : public WordCloud {
public:
    WordCloudCircle(int side);
    WordCloudCircle(int side, const std::vector<QString>& testWords); // для тестов
    bool checkPlace(int x, int y, const QString& word) override; // проверяет свободно ли место для слова в форме круга
};