# ====== Variables ======
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests

CXX := g++
CXXFLAGS := -Wall -std=c++17 -I$(INCLUDE_DIR)

# ====== TESTS ======
TEST_MEASUREMENT_SRC := $(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testMeasurement.cpp
TEST_PRIVATEUSER_SRC := $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(TEST_DIR)/testPrivateUser.cpp
TEST_SENSOR_SRC := $(SRC_DIR)/models/sensors/Sensor.cpp $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testSensor.cpp

TEST_MEASUREMENT_EXE := testMeasurement.exe
TEST_PRIVATEUSER_EXE := testPrivateUser.exe
TEST_SENSOR_EXE := testSensor.exe

# ====== EXECUTION NORMALE ======
MAIN_EXE := main
MAIN_SRC := main.cpp
AIR_CLEANER_SRC := AirCleaner.cpp
PROVIDER_SRC := AirCleanerProviderUser.cpp

# ====== Cibles ======
# Message par défaut si aucune cible n'est précisée
.DEFAULT_GOAL := error

# Cible : test
test: $(TEST_MEASUREMENT_EXE) $(TEST_PRIVATEUSER_EXE) $(TEST_SENSOR_EXE)

$(TEST_MEASUREMENT_EXE): $(TEST_MEASUREMENT_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_PRIVATEUSER_EXE): $(TEST_PRIVATEUSER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_SENSOR_EXE): $(TEST_SENSOR_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# ====== EXECUTION NORMALE ======
SRC_FILES := $(wildcard src/**/*.cpp) $(wildcard src/*.cpp) main.cpp
OBJ_FILES := $(SRC_FILES:.cpp=.o)
MAIN_EXE := main

exec: $(MAIN_EXE)

$(MAIN_EXE): $(OBJ_FILES)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cible : clean
clean:
	rm -f *.o $(MAIN_EXE) $(TEST_MEASUREMENT_EXE) $(TEST_PRIVATEUSER_EXE) $(TEST_SENSOR_EXE)

# Cible d'erreur par défaut
error:
	@echo "⚠️  Merci de préciser une cible :"
	@echo "    ➤ make test     : pour compiler les tests"
	@echo "    ➤ make exec     : pour compiler le programme principal"
	@echo "    ➤ make clean    : pour nettoyer les fichiers de compilation"
	@exit 1
