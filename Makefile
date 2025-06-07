# Dossiers
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests

# Compilateur et flags
CXX := g++
CXXFLAGS := -Wall -I$(INCLUDE_DIR) -std=c++17

# Sources et exécutables des tests
TEST_MEASUREMENT_SRC := $(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testMeasurement.cpp
TEST_PRIVATEUSER_SRC := $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(TEST_DIR)/testPrivateUser.cpp
TEST_SENSOR_SRC := $(SRC_DIR)/models/sensors/Sensor.cpp $(TEST_DIR)/testSensor.cpp $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(SRC_DIR)/models/sensors/Measurement.cpp

TEST_MEASUREMENT_EXE := testMeasurement.exe
TEST_PRIVATEUSER_EXE := testPrivateUser.exe
TEST_SENSOR_EXE := testSensor.exe

# Cibles par défaut : compiler tous les tests
all: $(TEST_MEASUREMENT_EXE) $(TEST_PRIVATEUSER_EXE) $(TEST_SENSOR_EXE)

# Règles de compilation des tests
$(TEST_MEASUREMENT_EXE): $(TEST_MEASUREMENT_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_PRIVATEUSER_EXE): $(TEST_PRIVATEUSER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_SENSOR_EXE): $(TEST_SENSOR_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TEST_MEASUREMENT_EXE) $(TEST_PRIVATEUSER_EXE) $(TEST_SENSOR_EXE) $(SRC_DIR)/**/*.o

.PHONY: all clean
