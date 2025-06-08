# Cible principale : création de l'exécutable
airCleanerTest: airCleanerTest.o AirCleaner.o
	g++ -Wall -g -o airCleanerTest airCleanerTest.o AirCleaner.o

# Compilation du fichier airCleanerTest.cpp
airCleanerTest.o: tests/airCleanerTest.cpp include/models/sensors/AirCleaner.h
	g++ -Wall -g -I./src -I./include -c tests/airCleanerTest.cpp -o airCleanerTest.o

# Compilation de AirCleaner.cpp
AirCleaner.o: src/models/sensors/AirCleaner.cpp include/models/sensors/AirCleaner.h include/utils/Util.h
	g++ -Wall -g -I./src -I./include -c src/models/sensors/AirCleaner.cpp -o AirCleaner.o

# Nettoyage
clean:
	rm -f airCleanerTest airCleanerTest.o AirCleaner.o

.PHONY: clean
