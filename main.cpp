#include <QCoreApplication>
#include <QImage>
#include <QPainter>
#include <QFont>
#include <iostream>
<<<<<<< HEAD

int main(int argc, char *argv[]){
    QCoreApplication app(argc, argv);
    
    // Создаем простое изображение 400x300
    QImage image(400, 300, QImage::Format_RGB32);
    image.fill(Qt::white);
    
    // Рисуем текст
    QPainter painter(&image);
    painter.setFont(QFont("Arial", 20));
    painter.setPen(Qt::blue);
    painter.drawText(50, 100, "Qt Works!");
    painter.setPen(Qt::red);
    painter.drawText(50, 150, "Hello World");
    
    // Сохраняем изображение
    if (image.save("test.jpg", "JPG")) {
        std::cout << "Qt test successful! Image saved as test.jpg" << std::endl;
    } else {
        std::cout << "Failed to save image" << std::endl;
    }
    
=======
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
>>>>>>> 4fd2da09a1db70f92c3d8d20404a982787b24f35
    return 0;
}