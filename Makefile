main: main.o
		g++ -o main main.o Ensemble.o

main.o: main.cpp
		g++ -c main.cpp

clean:
		rm -f main main.o Ensemble.o
