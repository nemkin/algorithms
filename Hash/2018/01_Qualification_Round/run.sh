g++ -o main -std=c++11 main.cpp

rm *.out

./main < c.in > c.out

rm code.zip
zip code.zip *.cpp *.py *.sh
