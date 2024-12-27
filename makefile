all: compile run

compile:
	g++ -I ./include/ -o ./lib/AgacDugum.o -c ./src/AgacDugum.cpp
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/AgaclarListesi.o -c ./src/AgaclarListesi.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./bin/Main ./lib/AgacDugum.o  ./lib/Agac.o  ./lib/Dugum.o ./lib/AgaclarListesi.o ./lib/Stack.o ./src/Main.cpp	
run:
	./bin/Main
