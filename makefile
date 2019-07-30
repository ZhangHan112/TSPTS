all: TSPTS

TSPTS: TSPTS.o main.o 
	g++ -ggdb -o TSPTS TSPTS.o main.o

TSPTS.o: TSPTS.cpp
	g++ -ggdb -c TSPTS.cpp

main.o: main.cpp
	g++ -ggdb -c main.cpp

plot: 
	gnuplot pic.gp

dep:
	echo "Do nothing"

clean:
	rm -f KPTS KPTS *.o

cleanDat:
	rm -f *.dat
