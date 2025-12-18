#include <gtest/gtest.h>
#include "struct.h"
#include <QApplication>
#include <QFile>
#include <QFileInfo>

class WordCloudTest : public ::testing::Test {
protected:
    void SetUp() override {
        if (!QApplication::instance()) {
            int argc = 0;
            char** argv = nullptr;
            app = new QApplication(argc, argv);
        }
    }
    
    QApplication* app = nullptr;
};

// Тест конструктора
TEST_F(WordCloudTest, ConstructorCreatesValidObject) {
    std::vector<QString> testWords = {"hello", "world"};
    WordCloud wc(500, testWords);
    EXPECT_EQ(wc.getSide(), 500);
}

// Тест метода getSize
TEST_F(WordCloudTest, GetSizeReturnsCorrectDimensions) {
    std::vector<QString> testWords = {"test"};
    WordCloud wc(500, testWords);
    QString testWord = "test";
    QSize size = wc.getSize(testWord);
    
    EXPECT_GT(size.width(), 0);
    EXPECT_GT(size.height(), 0);
}

// Тест метода getLeftTop
TEST_F(WordCloudTest, GetLeftTopCalculatesCorrectPosition) {
    std::vector<QString> testWords = {"hello"};
    WordCloud wc(500, testWords);
    QString word = "hello";
    QPoint leftTop = wc.getLeftTop(250, 250, word);
    
    EXPECT_GE(leftTop.x(), 0);
    EXPECT_GE(leftTop.y(), 0);
}

// Тест метода checkPlace
TEST_F(WordCloudTest, CheckPlaceValidatesPosition) {
    std::vector<QString> testWords = {"test"};
    WordCloud wc(500, testWords);
    QString word = "test";
    
    // Валидная позиция (не в центре, где есть ограничение)
    EXPECT_TRUE(wc.checkPlace(200, 100, word));
    
    // Невалидная позиция (за границами)
    EXPECT_FALSE(wc.checkPlace(-10, 100, word));
    EXPECT_FALSE(wc.checkPlace(100, -10, word));
    EXPECT_FALSE(wc.checkPlace(600, 100, word));
}

// Тест метода random
TEST_F(WordCloudTest, RandomGeneratesValidNumbers) {
    std::vector<QString> testWords = {"test"};
    WordCloud wc(500, testWords);
    
    for (int i = 0; i < 10; i++) {
        int randomNum = wc.random(10);
        EXPECT_GE(randomNum, 0);
        EXPECT_LE(randomNum, 10);
    }
}

// Тест сохранения изображения
TEST_F(WordCloudTest, SaveImageCreatesFile) {
    std::vector<QString> testWords = {"test"};
    WordCloud wc(500, testWords);
    wc.saveImage();
    
    QFileInfo fileInfo("../WordCloud.jpg");
    EXPECT_TRUE(fileInfo.exists());
}

// Тест для WordCloudCircle
TEST_F(WordCloudTest, CircleCheckPlaceRespectsBoundary) {
    std::vector<QString> testWords = {"test"};
    WordCloudCircle wcc(500, testWords);
    QString word = "test";
    
    // Центр круга - должно быть валидно
    EXPECT_TRUE(wcc.checkPlace(240, 240, word));
    
    // Край круга - может быть невалидно
    EXPECT_FALSE(wcc.checkPlace(10, 10, word));
}