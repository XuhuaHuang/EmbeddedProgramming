cmake_minimum_required(VERSION 3.20)

project("refactored_dealer" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(refactored_dealer
    "Card.hpp"
    "Client.hpp"
    "Deck.hpp"
    "ICardSource.hpp"
    "main.cpp"
)
