cmake_minimum_required(VERSION 3.20)

project("banking_accounts")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(banking_accounts
    "BankingAccounts.hpp"
    "BankingAccounts.cpp"
    "main.cpp"
)
