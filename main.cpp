#include <iostream>
#include <cmath>
#include <string>
#include <vector>

// класс отвечающий за облако слов
class WordCloud {
protected:
    std::vector<std::string> words;
public:
    // конструктор. собирает вектор со словами разделяя их по пробелу
    WordCloud(){
        std::cout << "write word for word cloud\n";
        std::string word;
        while (std::cin >> word){
            words.push_back(word);
            if (std::cin.peek() == '\n'){
                break;
            }
        }
    }
};

int main(){
    return 0;
}