# === Variables Générales ===
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests

CXX := g++
CXXFLAGS := -Wall -I$(INCLUDE_DIR) -std=c++17

# === Fichiers de test ===
TEST_MEASUREMENT_SRC := $(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testMeasurement.cpp
TEST_PRIVATEUSER_SRC := $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(TEST_DIR)/testPrivateUser.cpp
TEST_SENSOR_SRC := $(SRC_DIR)/models/sensors/Sensor.cpp $(TEST_DIR)/testSensor.cpp $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(SRC_DIR)/models/sensors/Measurement.cpp

TEST_MEASUREMENT_EXE := testMeasurement.exe
TEST_PRIVATEUSER_EXE := testPrivateUser.exe
TEST_SENSOR_EXE := testSensor.exe

# === Cibles principales ===
.PHONY: all test exec clean help

# Règle par défaut : affiche une erreur
all:
	@echo "❌ Erreur : vous devez spécifier une option :"
	@echo "    👉 make test   # pour compiler les tests"
	@echo "    👉 make exec   # pour compiler avec CMake"
	@echo "    👉 make clean  # pour tout nettoyer"
	@exit 1

# === Compilation des tests ===
test: $(TEST_MEASUREMENT_EXE) $(TEST_PRIVATEUSER_EXE) $(TEST_SENSOR_EXE)

$(TEST_MEASUREMENT_EXE): $(TEST_MEASUREMENT_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_PRIVATEUSER_EXE): $(TEST_PRIVATEUSER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_SENSOR_EXE): $(TEST_SENSOR_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# === Compilation du projet principal via CMake ===
exec:
	@mkdir -p build
	cd build && cmake .. && make

# === Nettoyage ===
clean:
	rm -f $(TEST_MEASUREMENT_EXE) $(TEST_PRIVATEUSER_EXE) $(TEST_SENSOR_EXE)
	rm -rf build
