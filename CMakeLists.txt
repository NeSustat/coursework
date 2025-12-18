cmake_minimum_required(VERSION 3.14)
project(WordCloudGenerator)

set(CMAKE_CXX_STANDARD 17)

# Найти Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# Подключение локального Google Test
add_subdirectory(googletest)

# Основная программа
add_executable(wordcloud main.cpp struct.cpp)
target_link_libraries(wordcloud Qt6::Core Qt6::Widgets Qt6::Gui)

# Тесты
add_executable(tests test_wordcloud.cpp struct.cpp)
target_link_libraries(tests gtest_main Qt6::Core Qt6::Widgets Qt6::Gui)

enable_testing()
add_test(NAME unit_tests COMMAND tests)
