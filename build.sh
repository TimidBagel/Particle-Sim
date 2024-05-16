#! /usr/bin/bash
g++ -c $1.cpp 
g++ $1.o -o $1-app -lsfml-graphics -lsfml-window -lsfml-system
