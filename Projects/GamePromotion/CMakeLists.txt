cmake_minimum_required(VERSION 3.20)

project("game_promotion" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(game_promotion
    "GamePromotion.hpp"
    "GamePromotion.cpp"
    "main.cpp"
)
