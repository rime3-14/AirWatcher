main: main.o AirCleaner.o AirCleanerProviderUser.o
		g++ -o main main.o AirCleaner.o AirCleanerProviderUser.o

main.o: main.cpp 
		g++ -c main.cpp

AirCleaner.o : AirCleaner.h AirCleaner.cpp
		g++ -c AirCleaner.cpp

AirCleanerProviderUser.o : AirCleanerProviderUser.h AirCleanerProviderUser.cpp
		g++ -c AirCleanerProviderUser.cpp

clean:
		rm -f main main.o AirCleaner.o AirCleanerProviderUser.o