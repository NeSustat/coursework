#include <QGuiApplication>
#include <iostream>
#include <locale>
#include "struct.h"


int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    int choice = 3;

    setlocale(LC_ALL, "Russian");
    system("chcp 1251"); 
    do {
        std::cout << "What kind of shape?\n 0 = exit\n 1 = circle\n 2 = square\n";
        std::cin >> choice;
        std::cout << "\n";
        if (choice == 1){
            int radius = 0;
            std::cout << "Enter radius\n";
            std::cin >> radius;
            std::cout << "\n";
            WordCloudCircle cloud(radius);
            cloud.drawFirstWord();
            cloud.saveImage();
            choice = 0;
        } else if (choice == 2){
            int side = 0;
            std::cout << "Enter side\n";
            std::cin >> side;
            std::cout << "\n";
            WordCloud cloud(side);
            cloud.drawFirstWord();
            cloud.saveImage();
            choice = 0;
        } else {
            std::cout << "error\n";
        }
    } while (choice != 0);
    
    return 0;
}