#include "struct.h"
#include <random>
#include <algorithm>

WordCloud::WordCloud(int side) : font("Ink Free"), side(side), freePlace(side, std::vector<bool>(side, false)), image(side, side, QImage::Format_RGB32){
    std::cout << "write word for word cloud\n";
    std::string word;
    while (std::cin >> word) {
        QString qword = QString::fromLocal8Bit(word.c_str());
        words.push_back(qword);
        if (std::cin.peek() == '\n') break;
    }
    image.fill(Qt::white);
    painter.begin(&image);
    std::cout << "start drawing\n";
}

void WordCloud::saveImage(){
    painter.end();
    if (image.save("../WordCloud.png", "PNG")) {
        std::cout << "Qt save successful! Image saved as WordCloud.png" << std::endl;
    } else {
        std::cout << "Failed to save image" << std::endl;
    }
}

bool WordCloud::checkPlace(int x, int y, const QString& word){
    QSize size = getSize(word);
    int width = size.width() + 2;
    int height = size.height() + 2;
    if (abs(x - side / 4) < side / 2 || y < 0 || x + width > side || y + height > side){
        return false;
    }
    for (int i = x; i < x + width; i++){
        for (int j = y; j < y + height; j++){
            if (freePlace[j][i]){
                return false;
            }
        }
    }
    return true;
}

void WordCloud::switchFlag(int x, int y, const QString& word){
    QSize size = getSize(word);
    int width = size.width() + 2;
    int height = size.height() + 2;
    for (int i = x; i < x + width; i++){
        for (int j = y; j < y + height; j++){
            freePlace[j][i] = true;
        }
    }
}

void WordCloud::drawFirstWord(){
    for (int i = side/5; i > 15; i -= 5){
        font.setPixelSize(i);
        painter.setFont(font);
        QPoint leftTop = getLeftTop(side / 2, side / 2, words[0]);
        if (checkPlace(leftTop.x(), leftTop.y(), words[0])){
            curPixel = i / 2;
            switchFlag(leftTop.x(), leftTop.y(), words[0]);
            painter.setFont(font);
            painter.setPen(Qt::red);
            QFontMetrics metrics(font);
            QRect rect = metrics.tightBoundingRect(words[0]);
            painter.drawText(leftTop.x() - rect.x(), leftTop.y() - rect.y(), words[0]);
            static std::random_device rd;
            static std::mt19937 gen(rd());
            if (words.size() > 5){
                words.erase(words.begin());
            }
            shuffle(words.begin(), words.end(), gen);
            drawWord();
            return;
        }
    }
    std::cout << "can't draw first word\n";
}

void WordCloud::drawWord(){
    for (int i = curPixel; i > 15; i -= 5){
        font.setPixelSize(i);
        painter.setFont(font);
        for (int radius = 0; radius < side / 2; radius += i*2){
            int direction[8][2] = {{radius + side / 2, 0 + side / 2}, {0 + side / 2, radius + side / 2}, 
                                    {radius + side / 2, radius + side / 2}, {-radius + side / 2, radius + side / 2}, 
                                    {-radius + side / 2, 0 + side / 2}, {0 + side / 2, -radius + side / 2}, 
                                    {radius + side / 2, -radius + side / 2}, {-radius + side / 2, -radius + side / 2}};
            for (int j = 0; j < 8; j++){
                QPoint leftTop = getLeftTop(direction[j][0], direction[j][1], words[curIndexWords]);
                if (checkPlace(leftTop.x(), leftTop.y(), words[curIndexWords])){
                    switchFlag(leftTop.x(), leftTop.y(), words[curIndexWords]);
                    painter.setPen(color[random(color.size() - 1)]);
                    QFontMetrics metrics(font);
                    QRect rect = metrics.tightBoundingRect(words[curIndexWords]);
                    painter.drawText(leftTop.x() - rect.x(), leftTop.y() - rect.y(), words[curIndexWords]);
                    if (curIndexWords == words.size() - 1){
                        curIndexWords = 0;
                    } else{
                        curIndexWords++;
                    }
                }
            }
        }
    }
    fullDraw();
}

void WordCloud::fullDraw(){
    for (int i = curPixel; i > 8; i -= 3){
        font.setPixelSize(i);
        painter.setFont(font);
        for (int x = 0; x < side; x += 3){
            for (int y = 0; y < side; y += 3){
                int randIndex = random(words.size() - 1);
                if (checkPlace(x, y, words[randIndex])){
                    switchFlag(x, y, words[randIndex]);
                    painter.setPen(color[random(color.size() - 1)]);
                    QFontMetrics metrics(font);
                    QRect rect = metrics.tightBoundingRect(words[randIndex]);
                    painter.drawText(x - rect.x(), y - rect.y(), words[randIndex]);
                }
            }
        }
    } 
}

int WordCloud::random(int max){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, max);
    return dis(gen);
}

QSize WordCloud::getSize(const QString& word){
    QFontMetrics metrics(font);
    QRect rect = metrics.tightBoundingRect(word);
    return QSize(rect.width(), rect.height());
}

QPoint WordCloud::getLeftTop(int centerX, int centerY, const QString& word){
    QFontMetrics metrics(font);
    QRect rect = metrics.tightBoundingRect(word);
    int x = centerX - rect.width() / 2;
    int y = centerY - rect.height() / 2;
    return QPoint(x, y);
}


WordCloudCircle::WordCloudCircle(int side) : WordCloud(side){}

bool WordCloudCircle::checkPlace(int x, int y, const QString& word){
    QSize size = getSize(word);
    int width = size.width() + 2;
    int height = size.height() + 2;
    if (x < 0 || y < 0 || x + width > side || y + height > side){
        return false;
    }
    int centerX = side / 2;
    int centerY = side / 2;
    int radius = side / 2;
    int corners[4][2] = {{x, y}, {x + width, y}, {x, y + height}, {x + width, y + height}};
    for (int i = 0; i < 4; i++) {
        int dx = corners[i][0] - centerX;
        int dy = corners[i][1] - centerY;
        if (dx*dx + dy*dy > radius*radius) {
            return false;
        }
    }
    for (int i = x; i < x + width; i++){
        for (int j = y; j < y + height; j++){
            if (freePlace[j][i]){
                return false;
            }
        }
    }
    return true;
}
