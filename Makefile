# ====== Directories ======
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests
BUILD_DIR := build

# ====== Compiler settings ======
CXX := g++
CXXFLAGS := -Wall -std=c++17 -g -I$(INCLUDE_DIR) -MMD -MP

# ====== Source Files ======
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
    $(SRC_DIR)/dataAccess/MeasurementRepository.cpp \
    $(SRC_DIR)/dataAccess/UserRepository.cpp \
    $(SRC_DIR)/dataAccess/SensorRepository.cpp \
    $(SRC_DIR)/utils/Util.cpp

MAIN_SRC := $(SRC_DIR)/main.cpp
MAIN_EXE := main

SRC_FILES := $(MAIN_SRC) $(COMMON_SRC) $(SRC_DIR)/dataAccess/CSVLoader.cpp

# ====== Object and Dependency Files ======
OBJ_FILES := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)

# ====== Map .cpp -> build/.o ======
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ====== Main executable ======
exec: $(MAIN_EXE)

$(MAIN_EXE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# ====== Test definitions ======
define MAKE_TEST_RULES
$(1)_SRC := $(2)
$(1)_OBJ := $$(patsubst %.cpp,$$(BUILD_DIR)/%.o,$$($(1)_SRC))
$(1) := $(1).exe

$$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $$(dir $$@)
	$$(CXX) $$(CXXFLAGS) -c $$< -o $$@

$$($(1)): $$($(1)_OBJ)
	$$(CXX) $$(CXXFLAGS) -o $$@ $$^

endef

# ====== Declare test rules ======
$(eval $(call MAKE_TEST_RULES,TEST_MEASUREMENT,$(SRC_DIR)/models/sensors/Measurement.cpp $(TEST_DIR)/testMeasurement.cpp))
$(eval $(call MAKE_TEST_RULES,TEST_PRIVATEUSER,$(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(TEST_DIR)/testPrivateUser.cpp))
$(eval $(call MAKE_TEST_RULES,TEST_SENSOR,$(SRC_DIR)/models/sensors/Sensor.cpp $(SRC_DIR)/models/sensors/Measurement.cpp $(SRC_DIR)/models/users/PrivateUser.cpp $(SRC_DIR)/models/users/User.cpp $(TEST_DIR)/testSensor.cpp))
$(eval $(call MAKE_TEST_RULES,TEST_CSVLOADER,$(SRC_DIR)/dataAccess/CSVLoader.cpp $(COMMON_SRC) $(TEST_DIR)/testCSVLoader.cpp))
$(eval $(call MAKE_TEST_RULES,TEST_SENSORREPOSITORY,$(SRC_DIR)/dataAccess/SensorRepository.cpp $(COMMON_SRC) $(TEST_DIR)/testSensorRepository.cpp))
$(eval $(call MAKE_TEST_RULES,TEST_MEASUREMENTREPOSITORY,$(SRC_DIR)/dataAccess/MeasurementRepository.cpp $(COMMON_SRC) $(TEST_DIR)/testMeasurementRepository.cpp))
$(eval $(call MAKE_TEST_RULES,TEST_AIRCLEANER,$(SRC_DIR)/models/sensors/AirCleaner.cpp $(COMMON_SRC) $(TEST_DIR)/testAirCleaner.cpp))
$(eval $(call MAKE_TEST_RULES,TEST_USERREPOSITORY,$(SRC_DIR)/dataAccess/UserRepository.cpp $(COMMON_SRC) $(TEST_DIR)/testUserRepository.cpp))

# ====== Group test targets ======
TEST_TARGETS := \
	$(TEST_MEASUREMENT) \
	$(TEST_PRIVATEUSER) \
	$(TEST_SENSOR) \
	$(TEST_CSVLOADER) \
	$(TEST_SENSORREPOSITORY) \
	$(TEST_MEASUREMENTREPOSITORY) \
	$(TEST_AIRCLEANER) \
	$(TEST_USERREPOSITORY)

test: $(TEST_TARGETS)
	@echo "✅ Compilation des tests réussie. Exécutez-les avec: make run-tests"

run-tests:
	@for exe in $(TEST_TARGETS); do \
		echo "\n===== Running $$exe ====="; \
		./$$exe || exit 1; \
	done

# ====== Clean ======
clean:
	rm -rf $(BUILD_DIR) *.exe $(MAIN_EXE)

# ====== Dependency includes ======
-include $(DEP_FILES)

# ====== Default goal ======
.DEFAULT_GOAL := exec