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
                std::cout << "In which are area would you like to view the mean air quality ?" << std::endl;
                std::cout << "Please enter the coordinates of the center area :" << std::endl;
                std::cout << "  - Latitude (e.g. 48.8566): ";
                float latitude;
                std::cin >> latitude;
                std::cout << "  - Longitude (e.g. 2.3522): ";
                float longitude;
                std::cin >> longitude;
                std::cout << "Please enter the radius of the area in meters (e.g. 1000): ";
                float radius;
                std::cin >> radius;
                std::cout << "Please enter the calculation start date (YYYY-MM-DD HH:MM:SS): ";
                std::string startDateStr;
                std::cin >> startDateStr;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                time_t startDate = stringToDate(startDateStr);
                std::cout << "Please enter calculation the end date (YYYY-MM-DD HH:MM:SS): ";
                std::string endDateStr;
                std::cin >> endDateStr;
                time_t endDate = stringToDate(endDateStr);
                algoPerformance.begin("EvaluateAQIAverages");
                vector<Sensor> sensors = sensorRepo.getSensorsInCircularRadius(latitude, longitude, radius);
                if (sensors.empty()) {
                    std::cout << "No sensors found in the specified area." << std::endl;
                    algoPerformance.end(); 
                    break;
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
            break;
            }
            case MenuAction::CompareAQISimilarity: {
                std::cout << "==== Compare AQI Similarity: ====\n";
                std::cout << "Which sensor would you like to compare against others ?" << std::endl;
                std::cout << "Please enter a sensor ID (e.g. Sensor0): ";
                std::string sensorId;
                std::cin >> sensorId;
                Sensor sensor = sensorRepo.getSensorById(sensorId);
                if (sensor.getId().empty()) {
                    std::cout << "Sensor with ID " << sensorId << " not found." << std::endl;
                    break;
                } else {
                    std::cout << "Sensor with ID" << sensorId << " successfully found." << std::endl; 
                }
                std::cout << "Please enter the start date (YYYY-MM-DD HH:MM:SS): ";
                std::string startDateStr;
                std::cin >> startDateStr;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                time_t startDate = stringToDate(startDateStr);
                std::cout << "Please enter the end date (YYYY-MM-DD HH:MM:SS): ";
                std::string endDateStr;
                std::cin >> endDateStr;
                time_t endDate = stringToDate(endDateStr);
               
                std::cout << "Comparing sensor " << sensorId << " against others..." << std::endl;
                algoPerformance.begin("EvaluateAQIAverages"); 
                std::vector<Sensor*> similarSensors = airQualityService.CompareSensorAgainstOthers(sensor, startDate, endDate);
                std::cout << "Comparison complete." << std::endl;

                std::cout << "Similar sensors ranked by air quality similarity:" << std::endl;
                int rank = 1; 
                for(Sensor * similarSensor : similarSensors) {
                    std::cout << rank << "." << similarSensor->getId(); 
                    std::cout << " | Location : (" << similarSensor->getLatitude() << ", " << similarSensor->getLongitude() << ")" << std::endl; 
                    rank++; 
                } 

                algoPerformance.end(); 
            break;
            }
            case MenuAction::CalculateAirCleanerImpact: {
                std::cout << "==== Calc AirTracker Impact: ====\n";
                std::cout << "Please enter an AirTracker ID (e.g. Cleaner0) : ";
                std::string airCleanerId; 
                std::cin >> airCleanerId; 
                AirCleaner airCleaner = airCleanerRepo.getAirCleanerById(airCleanerId);
                if (airCleaner.getId().empty()) {
                    std::cout << "Air Tracker with ID " << airCleanerId << " not found." << std::endl;
                    break;
                } else {
                    std::cout << "Air Tracker with ID" << airCleanerId << " successfully found." << std::endl; 
                }
                algoPerformance.begin("CalculateAirCleanerImpact"); 
                std::cout << "- Radius of air purified by the Air Tracker : " << airCleaner.calculateRadiusPurifiedAir() << std::endl;  
                std::cout << "- Level of AQI Improvement : " << airCleaner.calculateImprovedAirLevel() << std::endl; 
                algoPerformance.end(); 

            break;
            }
            case MenuAction::EvaluateAirTrackerReliability: {
                std::cout << "== Eval AirTracker Reliability: =\n";
                std::cout << "==== Compare AQI Similarity: ====\n";
                std::cout << "Which sensor would you like to evaluate its reliability ?" << std::endl;
                std::cout << "Please enter a sensor ID (e.g. Sensor0): ";
                std::string sensorId;
                std::cin >> sensorId;

                algoPerformance.begin("EvaluateAirTrackerReliability");

                Sensor sensor = sensorRepo.getSensorById(sensorId);
                if (sensor.getId().empty()) {
                    std::cout << "Sensor with ID " << sensorId << " not found." << std::endl;
                    break;
                } else {
                    std::cout << "Sensor with ID" << sensorId << " successfully found." << std::endl; 
                }

                bool isReliable = sensor.getReliability(); 
                vector<Sensor> nearbySensors = sensorRepo.getSensorsInCircularRadius(sensor.getLatitude(),sensor.getLongitude(),100000); // Rayon de 100 km
                float deviation = reliabilityService.calculateZScoreDeviationBetween(sensor, nearbySensors); 
                std::cout << "Estimated deviation between the sensor and nearby sensors in a 100 km radius : " << deviation << endl; 

                if(isReliable) {
                    std::cout << "The sensor is currently marked as reliable." << std::endl; 
                    std::cout << "Do you wish to mark it as unreliable ? [Y/N] "; 
                    char response; 
                    std::cin >> response; 
                    while(response != 'Y' && response != 'N') {
                        std::cout << "Invalid input. Please choose between 'Yes' (Y) or 'No' (N). "; 
                        std::cin >> response; 
                    }
                    if(response == 'Y') {
                        sensorRepo.markSensorAsUnreliable(sensor); 
                        std::cout << sensor.getId() << " has been successfully marked as unreliable." << std::endl; 
                    }
                } else {
                    std::cout << "The sensor is already marked as unreliable." << std::endl; 
                }

                algoPerformance.end(); 

            break;
            }
            case MenuAction::EvaluatePrivateSubmission: {
                std::cout << "==== Eval Private Submission: ===\n";
                 std::cout << "Which individual would you like to view the data of ?" << std::endl;
                std::cout << "Please enter a Private User ID (e.g. User0): ";
                std::string userId;
                std::cin >> userId;

                algoPerformance.begin("EvaluatePrivateSubmission");

                PrivateUser privateUser = userRepo.getPrivateUserById(userId); 
                if (privateUser.getId().empty()) {
                    std::cout << "Private User with ID " << userId << " not found." << std::endl;
                    break;
                } else {
                    std::cout << "Private User with ID" << userId << " successfully found." << std::endl << endl; 
                }

                std::cout << "AirTrackers provided by " << userId << ": " << std::endl; 
                vector<string> sensorsId = privateUser.getSensorsId(); 
                int sensorPosition = 1; 
                for(string sId : sensorsId) {
                    Sensor sensor = sensorRepo.getSensorById(sId);
                    if (sensor.getId().empty()) {
                        continue;
                    }  
                    vector<Sensor> nearbySensors = sensorRepo.getSensorsInCircularRadius(sensor.getLatitude(),sensor.getLongitude(),100000); // Rayon de 100 km
                    float deviation = reliabilityService.calculateZScoreDeviationBetween(sensor, nearbySensors); 
                    Sensor s = sensorRepo.getSensorById(sId); 
                    std::cout << "  " << sensorPosition << ". " << sensor.getId() << std::endl; 
                    std::cout << "      " << "Currently Reliable ? " << (sensor.getReliability() ? "yes" : "no")<< std::endl; 
                    std::cout << "      " << "Deviation : " << deviation << std::endl; 
                    sensorPosition++; 
                } 
                std::cout << std::endl << "Note : To mark any sensor above as unreliable, please refer to option 'EvaluateAirTrackerReliability'" << endl; 
                algoPerformance.end(); 
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
        std::cout << "Please select a number from above: ";
        std::cout << std::flush;

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