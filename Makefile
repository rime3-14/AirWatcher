# ====== Variables ======
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests

CXX := g++
CXXFLAGS := -Wall -std=c++17 -I$(INCLUDE_DIR)
COMMON_SRC := \
	$(SRC_DIR)/models/sensors/Measurement.cpp \
	$(SRC_DIR)/models/sensors/Sensor.cpp \
	$(SRC_DIR)/models/sensors/AirCleaner.cpp \
	$(SRC_DIR)/models/users/User.cpp \
	$(SRC_DIR)/models/users/PrivateUser.cpp \
	$(SRC_DIR)/models/users/AirCleanerProviderUser.cpp \
	$(SRC_DIR)/models/users/GovernmentUser.cpp \
	$(SRC_DIR)/console/AuthManager.cpp \
	$(SRC_DIR)/console/ConsoleUI.cpp
MAIN_SRC := $(SRC_DIR)/main.cpp

# ====== TESTS ======
TEST_MEASUREMENT_SRC := $(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testMeasurement.cpp
TEST_PRIVATEUSER_SRC := $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(TEST_DIR)/testPrivateUser.cpp
TEST_SENSOR_SRC := $(SRC_DIR)/models/sensors/Sensor.cpp $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testSensor.cpp
TEST_CSVLOADER_SRC := $(SRC_DIR)/dataAccess/CSVLoader.cpp $(COMMON_SRC) $(TEST_DIR)/testCSVLoader.cpp

TEST_MEASUREMENT_EXE := testMeasurement.exe
TEST_PRIVATEUSER_EXE := testPrivateUser.exe
TEST_SENSOR_EXE := testSensor.exe
TEST_CSVLOADER_EXE := testCSVLoader.exe

# Message par défaut si aucune cible n'est précisée
.DEFAULT_GOAL := error

# Cible : test
test: $(TEST_MEASUREMENT_EXE) $(TEST_PRIVATEUSER_EXE) $(TEST_SENSOR_EXE) $(TEST_CSVLOADER_EXE)
	@echo "Compilation des tests réussie. Executions de tous les tests : `make run-tests`"

$(TEST_MEASUREMENT_EXE): $(TEST_MEASUREMENT_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_PRIVATEUSER_EXE): $(TEST_PRIVATEUSER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_SENSOR_EXE): $(TEST_SENSOR_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_CSVLOADER_EXE): $(TEST_CSVLOADER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Cible : run-tests
# Exécute les tests compilés
run-tests:
	@echo "\n======================  Exécutions de tous les tests.  =============================\n"
	@echo "====================================================================================\n"
	@echo "=====================  Executions de $(TEST_MEASUREMENT_EXE).  ========================\n"
	@./$(TEST_MEASUREMENT_EXE)
	@echo "\n=====================  Executions de $(TEST_PRIVATEUSER_EXE).  =======================\n"
	@./$(TEST_PRIVATEUSER_EXE)
	@echo "\n=====================  Executions de $(TEST_SENSOR_EXE).  =======================\n"
	@./$(TEST_SENSOR_EXE)
	@echo "\n===================  Executions de $(TEST_CSVLOADER_EXE).  =======================\n"
	@./$(TEST_CSVLOADER_EXE)
	@echo "\n================================================================================\n\n"


# ====== EXECUTION NORMALE ======
SRC_FILES := $(MAIN_SRC) $(COMMON_SRC) $(SRC_DIR)/dataAccess/CSVLoader.cpp
OBJ_FILES := $(SRC_FILES:.cpp=.o)
MAIN_EXE := main

exec: $(MAIN_EXE)

$(MAIN_EXE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@



# Cible : clean
clean:
	rm -f *.o $(MAIN_EXE) $(TEST_MEASUREMENT_EXE) $(TEST_PRIVATEUSER_EXE) $(TEST_SENSOR_EXE) $(TEST_CSVLOADER_EXE)

# Cible d'erreur par défaut
error:
	@echo "⚠️  Merci de préciser une cible :"
	@echo "    ➤ make test     : pour compiler les tests"
	@echo "    ➤ make exec     : pour compiler le programme principal"
	@echo "    ➤ make clean    : pour nettoyer les fichiers de compilation"
	@exit 1
