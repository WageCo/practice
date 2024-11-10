#!/bin/bash

g++ -std=c++2b main.cpp && ./a.out <input.txt >log
diff output.txt log
rm log a.out
