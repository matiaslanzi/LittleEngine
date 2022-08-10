#! /bin/bash

/usr/bin/clang++ -std=c++17 -g ../src/*.cpp -o ../bin/Application.app -lSDL2 -lSDL2_ttf -lSDL2_image
