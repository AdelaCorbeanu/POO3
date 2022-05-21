cmake_minimum_required(VERSION 3.21)
project(pisici)

set(CMAKE_CXX_STANDARD 14)

add_executable(pisici main.cpp human.cpp member.cpp leader.cpp team.cpp memento.cpp)
