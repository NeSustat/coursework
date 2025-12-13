cmake_minimum_required(VERSION 3.16)
project(wordcloud)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui)

file(GLOB SOURCES "*.cpp")

add_executable(wordcloud ${SOURCES})
target_link_libraries(wordcloud Qt6::Core Qt6::Gui)