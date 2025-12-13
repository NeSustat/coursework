#include "struct.h"

WordCloud::WordCloud(){
    std::cout << "write word for word cloud\n";
        std::string word;
        while (std::cin >> word){
            words.push_back(word);
            if (std::cin.peek() == '\n'){
                break;
            }
        }
        WordCloud::len = words.size();
}

bool WordCloud::checkPlace(int x, int y, std::string& word, const QFont font){

}

void WordCloud::switchFlagFreePlace(int x, int y, const std::string& word, const QFont& font){

}

QSize WordCloud::getSize(const std::string& word, const QFont& font){

}

void WordCloud::drawFirstWord(){

}

void WordCloud::drawWord(){

}