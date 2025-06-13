//
// Created by Christopher Wilson on 27/05/2025.
//

#include "console/ConsoleUI.h"
#include "services/AirQualityService.h"
#include "services/ReliabilityService.h"
#include "services/AlgoPerformance.h"

#include "dataAccess/SensorRepository.h"
#include "dataAccess/MeasurementRepository.h"
#include "dataAccess/AirCleanerRepository.h"
#include "dataAccess/UserRepository.h"

#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <ctime>
#include "utils/Util.h"


void ConsoleUI::run()
{
    static AlgoPerformance algoPerformance; 
    std::cout << "Welcome to AirWatcher\n";
    std::cout << "You can use this tool to access different information regarding air quality of the area.\n\n";

    std::cout << "============ Log in: ============\n";
    std::cout << "To begin, you need to log in\n\n";

    // Log user in
    while (authenticated_user == nullptr)
    {
        authenticated_user = AuthManager::login();
    }

    std::cout << "Successfully logged in\n";
    std::cout << "=================================\n\n";

    // Perform main application loop
    while (true)
    {
        std::cout << "=========== Main menu: ==========\n";

        MenuAction action = select_action();

        if (action == MenuAction::Quit)
        {
            break;
        }

        std::cout << "=================================\n\n";

        AirQualityService airQualityService;
        ReliabilityService reliabilityService; 

        MeasurementRepository measurementRepo; 
        SensorRepository sensorRepo;
        AirCleanerRepository airCleanerRepo; 
        UserRepository userRepo; 

        

        switch (action)
        {
            case MenuAction::EvaluateAQIAverages: {
                std::cout << "===== Evaluate AQI Averages: ====\n";
                evaluate_AQI_averages();
            break;
            }
            case MenuAction::CompareAQISimilarity: {
                std::cout << "==== Compare AQI Similarity: ====\n";
                compare_AQI_similarity();
            break;
            }
            case MenuAction::CalculateAirCleanerImpact: {
                std::cout << "==== Calc AirTracker Impact: ====\n";
                calculate_air_cleaner_impact();
            break;
            }
            case MenuAction::EvaluateAirTrackerReliability: {
                std::cout << "== Eval AirTracker Reliability: =\n";
                evaluate_air_tracker_reliability();
            break;
            }
            case MenuAction::EvaluatePrivateSubmission: {
                std::cout << "==== Eval Private Submission: ===\n";
                evaluate_private_submission();
            break;
            }
            case MenuAction::SharePrivateData:
                std::cout << "====== Share Private Data: ======\n";
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::ViewPerformanceMetrics: {
                std::cout << "==== View Performance Metrics: ===\n";
                algoPerformance.displayAllPerformances(); 
            break;
            }
            default: ;
        }
        std::cout << "=================================\n\n";
    }

    std::cout << "=================================\n\n";

}

MenuAction ConsoleUI::select_action() const
{
    const UserType role = authenticated_user->getRole();

    std::cout << "What would you like to do?\n\n";

    std::vector<const MenuOption*> availableOptions;

    for (const auto& option : menuOptions) {
        if (std::find(option.allowedRoles.begin(), option.allowedRoles.end(), role) != option.allowedRoles.end()) {
            availableOptions.push_back(&option);
        }
    }

    for (int i = 0; (size_t)i < availableOptions.size(); i++) {
        std::cout << i + 1 << " - " << availableOptions[i]->title << ":\n";
        std::cout << "    " << availableOptions[i]->description << "\n\n";
    }

    std::cout << "(Note: AQI = Air Quality Index)\n\n";

    while (true)
    {
        std::cout << "Please select a number from above: " << std::flush;
        int choice;

        // Check input is a number
        if (!(std::cin >> choice)) {
            // clear error state
            std::cin.clear();

            // discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice < 1 || (size_t)choice > availableOptions.size()) {
            std::cout << "Invalid input. Please enter a number from 1 to " << availableOptions.size() << ".\n";
            continue;
        }

        return availableOptions.at(choice - 1)->menu_action;
    }
}

void ConsoleUI::evaluate_AQI_averages()
{
    AirQualityService airQualityService;
    MeasurementRepository measurementRepo;
    SensorRepository sensorRepo;
    static AlgoPerformance algoPerformance;

    std::cout << "You first need to specify a circular area where mean air quality will be calculated\n";
    std::cout << "1. Enter the coordinates for the centre of the circular area\n";
    float latitude  = getValidFloat("   - Latitude (e.g. 48.8566): ");
    float longitude = getValidFloat("   - Longitude (e.g. 2.3522): ");

    std::cout << "2. Enter the radius of the circular area\n";
    float radius = getValidFloat("   - Radius in meters (e.g. 10000): ");

    std::cout << "\nYou now need to specify a time range to calculate mean air quality during\n";
    std::cout << "1. Enter the calculation start date (in format YYYY-MM-DD HH:MM:SS)\n";

    time_t startDate = getValidDate("   - Start date (e.g. 2019-01-01 00:00:00): ");

    std::cout << "2. Enter the calculation end date (in format YYYY-MM-DD HH:MM:SS)" << std::endl;
    time_t endDate   = getValidDate("   - End date (e.g. 2019-12-01 00:00:00): ");

    algoPerformance.begin("EvaluateAQIAverages");
    vector<Sensor> sensors = sensorRepo.getSensorsInCircularRadius(latitude, longitude, radius);

    if (sensors.empty()) {
        std::cout << "No sensors found in the specified area." << std::endl;
        algoPerformance.end();
        return;
    } else {
        std::cout << sensors.size() << " sensors found in the specified area." << std::endl;
        for (const Sensor& sensor : sensors) {
            std::cout << sensor.getId() << " | Location: (" << sensor.getLatitude() << ", " << sensor.getLongitude() << ")" << std::endl;
        }
    }

    std::cout << std::endl << "Evaluating AQI averages in area centered at (" << latitude << ", " << longitude << ") with a " << radius << " meters radius ..." << std::endl << std::endl;

    vector<MeasurementGroup> measurements = measurementRepo.getAllMeasurementsInTimeRange(sensors, startDate, endDate);
    std::cout << "Found " << measurements.size() << " measurements in the specified time range." << std::endl;
    float averageAQI = airQualityService.CalculateAvgAirQuality(measurements);
    std::cout << "Average AQI calculated successfully." << std::endl << std::endl;
    std::cout << "→ Average AQI in the specified area: " << averageAQI << std::endl;
    algoPerformance.end();
}

void ConsoleUI::compare_AQI_similarity() {
    AirQualityService airQualityService;
    SensorRepository sensorRepo;
    static AlgoPerformance algoPerformance;

    std::cout << "Which sensor would you like to compare against others ?\n";
    std::cout << "Please enter a sensor ID (e.g. Sensor0): " << std::flush;
    std::string sensorId;
    std::cin >> sensorId;

    Sensor sensor = sensorRepo.getSensorById(sensorId);
    if (sensor.getId().empty()) {
        std::cout << "Sensor with ID " << sensorId << " not found.\n";
        return;
    }
    std::cout << "Sensor with ID " << sensorId << " successfully found.\n";

    time_t startDate = getValidDate("Please enter the start date (YYYY-MM-DD HH:MM:SS): ");
    time_t endDate = getValidDate("Please enter the end date (YYYY-MM-DD HH:MM:SS): ");

    std::cout << "Comparing sensor " << sensorId << " against others...\n";
    algoPerformance.begin("CompareAQISimilarity");

    std::vector<Sensor*> similarSensors = airQualityService.CompareSensorAgainstOthers(sensor, startDate, endDate);

    std::cout << "Comparison complete.\n";
    std::cout << "Similar sensors ranked by air quality similarity:\n";
    int rank = 1;
    for (Sensor* s : similarSensors) {
        std::cout << rank++ << ". " << s->getId()
                  << " | Location: (" << s->getLatitude() << ", " << s->getLongitude() << ")\n";
    }

    algoPerformance.end();
}

void ConsoleUI::calculate_air_cleaner_impact() {
    AirCleanerRepository airCleanerRepo;
    static AlgoPerformance algoPerformance;

    std::cout << "Please enter an AirTracker ID (e.g. Cleaner0): " << std::flush;
    std::string airCleanerId;
    std::cin >> airCleanerId;

    AirCleaner airCleaner = airCleanerRepo.getAirCleanerById(airCleanerId);
    if (airCleaner.getId().empty()) {
        std::cout << "Air Tracker with ID " << airCleanerId << " not found.\n";
        return;
    }

    std::cout << "Air Tracker with ID " << airCleanerId << " successfully found.\n";

    algoPerformance.begin("CalculateAirCleanerImpact");
    std::cout << "- Radius of air purified: " << airCleaner.calculateRadiusPurifiedAir() << " m\n";
    std::cout << "- AQI improvement level: " << airCleaner.calculateImprovedAirLevel() << "\n";
    algoPerformance.end();
}

void ConsoleUI::evaluate_air_tracker_reliability() {
    SensorRepository sensorRepo;
    ReliabilityService reliabilityService;
    static AlgoPerformance algoPerformance;

    std::cout << "Which sensor would you like to evaluate?\n";
    std::cout << "Please enter a sensor ID (e.g. Sensor0): " << std::flush;
    std::string sensorId;
    std::cin >> sensorId;

    algoPerformance.begin("EvaluateAirTrackerReliability");

    Sensor sensor = sensorRepo.getSensorById(sensorId);
    if (sensor.getId().empty()) {
        std::cout << "Sensor with ID " << sensorId << " not found.\n";
        return;
    }

    std::cout << "Sensor with ID " << sensorId << " successfully found.\n";

    bool isReliable = sensor.getReliability();
    std::vector<Sensor> nearbySensors =
        sensorRepo.getSensorsInCircularRadius(sensor.getLatitude(), sensor.getLongitude(), 100000);

    float deviation = reliabilityService.calculateZScoreDeviationBetween(sensor, nearbySensors);
    std::cout << "Deviation from nearby sensors (100km radius): " << deviation << "\n";

    if (isReliable) {
        std::cout << "Sensor is currently marked as reliable.\n";
        std::cout << "Do you want to mark it as unreliable? [Y/N]: " << std::flush;
        char response;
        std::cin >> response;
        while (response != 'Y' && response != 'N') {
            std::cout << "Invalid input. Please enter Y or N: " << std::flush;
            std::cin >> response;
        }
        if (response == 'Y') {
            sensorRepo.markSensorAsUnreliable(sensor);
            std::cout << sensor.getId() << " marked as unreliable.\n";
        }
    } else {
        std::cout << "Sensor is already marked as unreliable.\n";
    }

    algoPerformance.end();
}

void ConsoleUI::evaluate_private_submission() {
    UserRepository userRepo;
    SensorRepository sensorRepo;
    ReliabilityService reliabilityService;
    static AlgoPerformance algoPerformance;

    std::cout << "Enter a Private User ID (e.g. User0): " << std::flush;
    std::string userId;
    std::cin >> userId;

    algoPerformance.begin("EvaluatePrivateSubmission");

    PrivateUser privateUser = userRepo.getPrivateUserById(userId);
    if (privateUser.getId().empty()) {
        std::cout << "Private User with ID " << userId << " not found.\n";
        return;
    }

    std::cout << "Private User " << userId << " found.\n";
    std::cout << "AirTrackers provided by " << userId << ":\n";

    std::vector<std::string> sensorsId = privateUser.getSensorsId();
    int i = 1;
    for (const std::string& id : sensorsId) {
        Sensor sensor = sensorRepo.getSensorById(id);
        if (sensor.getId().empty()) continue;

        std::vector<Sensor> nearbySensors =
            sensorRepo.getSensorsInCircularRadius(sensor.getLatitude(), sensor.getLongitude(), 100000);
        float deviation = reliabilityService.calculateZScoreDeviationBetween(sensor, nearbySensors);

        std::cout << "  " << i++ << ". " << sensor.getId() << "\n";
        std::cout << "      Reliable? " << (sensor.getReliability() ? "Yes" : "No") << "\n";
        std::cout << "      Deviation: " << deviation << "\n";
    }

    std::cout << "\nNote: To mark any sensor as unreliable, use 'EvaluateAirTrackerReliability'\n";

    algoPerformance.end();
}

float ConsoleUI::getValidFloat(const std::string& prompt)
{
    float value;
    while (true) {
        std::cout << prompt << std::flush;
        std::cin >> value;

        if (std::cin.fail()) {
            // Input was not a valid float
            std::cin.clear(); // clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a valid float.\n";
        } else {
            // Input is valid
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard any extra input
            return value;
        }
    }
}

time_t ConsoleUI::getValidDate(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt << std::flush;
        std::cin >> input;

        try {
            return stringToDate(input);
        } catch (const std::exception& e) {
            std::cout << "Invalid input. Please use format YYYY-MM-DD or YYYY-MM-DD HH:MM:SS.\n";
        }
    }
}