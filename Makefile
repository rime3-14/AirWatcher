# ====== Directories ======
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests
BUILD_DIR := build

# ====== Compiler settings ======
CXX := g++
CXXFLAGS := -Wall -std=c++17 -g -I$(INCLUDE_DIR) -MMD -MP

# ====== Source Files ======
MAIN_SRC := $(SRC_DIR)/main.cpp

COMMON_SRC := \
    $(SRC_DIR)/models/sensors/Measurement.cpp \
    $(SRC_DIR)/models/sensors/Sensor.cpp \
    $(SRC_DIR)/models/sensors/AirCleaner.cpp \
    $(SRC_DIR)/models/users/User.cpp \
    $(SRC_DIR)/models/users/PrivateUser.cpp \
    $(SRC_DIR)/models/users/AirCleanerProviderUser.cpp \
    $(SRC_DIR)/models/users/GovernmentUser.cpp \
    $(SRC_DIR)/console/AuthManager.cpp \
    $(SRC_DIR)/console/ConsoleUI.cpp \
    $(SRC_DIR)/dataAccess/CSVLoader.cpp \
    $(SRC_DIR)/dataAccess/MeasurementRepository.cpp \
    $(SRC_DIR)/dataAccess/UserRepository.cpp \
    $(SRC_DIR)/dataAccess/SensorRepository.cpp \
    $(SRC_DIR)/utils/Util.cpp \
    $(SRC_DIR)/services/AirQualityService.cpp \
    $(SRC_DIR)/services/AlgoPerformance.cpp \
    $(SRC_DIR)/services/Service.cpp

SRC_FILES := $(MAIN_SRC) $(COMMON_SRC)
OBJ_FILES := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)

# ====== Mapping compilation ======
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ====== Main Executable ======
MAIN_EXE := AirWatcher
exec: $(MAIN_EXE)

$(MAIN_EXE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# ====== Tests definitions ======
define TEST
TEST_$(1)_SRC := $(2)
TEST_$(1)_OBJ := $$(patsubst %.cpp,$$(BUILD_DIR)/%.o,$$(TEST_$(1)_SRC))
TEST_$(1)_EXE := test$(1).exe
TEST_TARGETS += $$(TEST_$(1)_EXE)

$$(TEST_$(1)_EXE): $$(TEST_$(1)_OBJ)
	$$(CXX) $$(CXXFLAGS) -o $$@ $$^
endef

# ====== Declaring test cases ======
$(eval $(call TEST,Measurement,$(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testMeasurement.cpp))
$(eval $(call TEST,PrivateUser,$(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(TEST_DIR)/testPrivateUser.cpp))
$(eval $(call TEST,Sensor,$(SRC_DIR)/models/sensors/Sensor.cpp $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testSensor.cpp))
$(eval $(call TEST,CSVLoader,$(COMMON_SRC) $(TEST_DIR)/testCSVLoader.cpp))
$(eval $(call TEST,SensorRepository,$(COMMON_SRC) $(TEST_DIR)/testSensorRepository.cpp))
$(eval $(call TEST,MeasurementRepository,$(COMMON_SRC) $(TEST_DIR)/testMeasurementRepository.cpp))
$(eval $(call TEST,AirCleaner,$(COMMON_SRC) $(TEST_DIR)/testAirCleaner.cpp))
$(eval $(call TEST,UserRepository,$(COMMON_SRC) $(TEST_DIR)/testUserRepository.cpp))
$(eval $(call TEST,AirQualityService,$(COMMON_SRC) $(TEST_DIR)/testAirQualityService.cpp))
$(eval $(call TEST,AlgoPerformance,$(COMMON_SRC) $(TEST_DIR)/testAlgoPerformance.cpp))

# ====== Cibles tests ======
test: $(TEST_TARGETS)
	@echo "✅ Compilation des tests réussie. Utilisez 'make run-tests' pour les lancer."

run-tests:
	@for exe in $(TEST_TARGETS); do \
		echo "\n\n====================================================================================="; \
		echo "\n======================== Running $$exe =========================="; \
		echo "\n======================================================================================\n"; \
		./$$exe || exit 1; \
	done

# ====== Clean ======
clean:
	rm -rf $(BUILD_DIR) $(MAIN_EXE) $(TEST_TARGETS)

# ====== Dépendances ======
-include $(DEP_FILES)

.DEFAULT_GOAL := exec
