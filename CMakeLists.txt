cmake_minimum_required(VERSION 3.9)
project(AlgoritmoDeHuffman)

set(CMAKE_CXX_STANDARD 11)

add_executable(AlgoritmoDeHuffman main.cpp CharFreqInVector.h CharFreqInVector.cpp Decompressor.h Decompressor.cpp FileLoader.h FileLoader.cpp GenerateHuffFile.h GenerateHuffFile.cpp LeafNode.h LeafNode.cpp Node.h Node.cpp TreeFromListConstruction.h TreeFromListConstruction.cpp)