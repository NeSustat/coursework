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
}