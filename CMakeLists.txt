cmake_minimum_required(VERSION 3.10)
project(MatrixTransposeAVX128)

set(CMAKE_CXX_STANDARD 17)

add_executable(main 
    main.cpp 
    matrixTranspose.cpp
    matrixTransposeAvx.cpp 
)