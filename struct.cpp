#include "struct.h"

WordCloud::WordCloud(int side){
    std::cout << "write word for word cloud\n";
        std::string word;
        while (std::cin >> word){
            words.push_back(word);
            if (std::cin.peek() == '\n'){
                break;
            }
        }
        WordCloud::sideCircle = side;
}

bool WordCloud::checkPlace(int x, int y, std::string& word, const QFont font){
    int width, lenght;
    QSize sizeWord = getSize(word, font);
    width = sizeWord.width;
    lenght = sizeWord.lenght;
    if (x < 0 || y < 0 || x + lenght > 512 || y + wight > 512){
        return false;
    }
    for (int i = x; i < x + lenght; i++){
        for (int j = y; j < y + width; j++){
            if (freePlase[i][j]){
                return false;
            }
        }
    }
    return true;
}

void switchFlag(int x, int y, const std::string& word, const QFont& font){
    int width, lenght;
    QSize sizeWord = getSize(word, font);
    width = sizeWord.width;
    lenght = sizeWord.lenght;
    for (int i = x; i < x + lenght; i++){
        for (int j = y; j < y + width; j++){
            freePlase[i][j] = true;
        }
    }
}

QSize WordCloud::getSize(const std::string& word, const QFont& font){

}

void WordCloud::drawFirstWord(){
    QSize size = getSize(words[0], )
}

void WordCloud::drawWord(){

}