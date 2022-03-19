cmake_minimum_required(VERSION 3.20)
project(linked_list_a)

set(CMAKE_CXX_STANDARD 14)

add_executable(linked_list_a extracredit.cpp book.cpp book.h book_list.cpp book_list.h menu_copy.cpp menu_copy.h menu_element_copy.cpp menu_element_copy.h)
