#include <QCoreApplication>
#include <QImage>
#include <QPainter>
#include <QFont>
#include <iostream>

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
    return 0;
}