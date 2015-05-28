all:
	clear
	g++ *.cpp -std=c++11 -o Gra -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	./Gra