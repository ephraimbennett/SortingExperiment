cmake_minimum_required(VERSION 3.5.0)
project(HW5 VERSION 0.1.0 LANGUAGES C CXX)


add_executable(HW5 main.cpp Merge.cpp Insertion.cpp)
target_compile_options(HW5 PRIVATE -O3 -march=native -flto -fopenmp)


