cmake_minimum_required(VERSION 3.10)
project(AddressBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(AddressBook 
    src/main.cpp
    src/Contact.cpp
    src/AddressBook.cpp
)

target_link_libraries(AddressBook PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(AddressBook PRIVATE include)

