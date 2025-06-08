//
// Created by Christopher Wilson on 27/05/2025.
//

#include "console/ConsoleUI.h"

#include "console/AuthManager.h"

#include "models/users/UserTypeEnum.h"

#include <iostream>
#include <stdexcept>

MenuAction ConsoleUI::select_action() const
{
    const UserType role = authenticated_user->getRole();

    std::cout << "What would you like to do?\n";

    std::vector<const MenuOption*> availableOptions;

    for (const auto& option : menuOptions) {
        if (std::find(option.allowedRoles.begin(), option.allowedRoles.end(), role) != option.allowedRoles.end()) {
            availableOptions.push_back(&option);
        }
    }

    for (int i = 0; i < availableOptions.size(); i++) {
        std::cout << i + 1 << " - " << availableOptions[i]->title << ": " << availableOptions[i]->description << "\n";
    }

    std::cout << "(Note: AQI = Air Quality Index)\n";
    std::cout << "Please select a number from above: ";
    std::cout << std::flush;

    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > availableOptions.size()) {
        throw std::runtime_error("Invalid selection");
    }

    return availableOptions.at(choice - 1)->menu_action;
}

void ConsoleUI::run()
{
    std::cout << "Welcome to AirWatcher\n";
    std::cout << "You can use this tool to access different information regarding air quality of the area.\n";

    std::cout << "To begin you need to log in.\n";

    // Log user in
    AuthManager authManager;
    authenticated_user = authManager.login();

    if (authenticated_user == nullptr)
        throw std::runtime_error("User not authenticated");

    // Perform main application loop
    MenuAction action;
    do {
        action = select_action();

        switch (action)
        {
            case MenuAction::Quit:
                std::cout << "Exiting App" << std::endl;
            break;
            case MenuAction::EvaluateAQIAverages:
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::CompareAQISimilarity:
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::CalculateAirTrackerImpact:
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::EvaluateAirTrackerReliability:
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::EvaluatePrivateSubmission:
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::SharePrivateData:
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::ViewPerformanceMetrics:
                std::cout << "Not yet implemented" << std::endl;
            break;
        }
    } while (action != MenuAction::Quit);


    // std::cout << "1 - Evaluate AQI averages (FR3)\n";
    // std::cout << "    Specify an area and period of time, and view the mean air quality\n";
    //
    // std::cout << "2 - Compare AQI similarity between sensors: (FR2)\n";
    // std::cout << "    Choose a sensor and rank all others based on similarity of air quality averages.\n";
    //
    // std::cout << "3 - Calculate an AirTracker's impact on air quality (FR4)\n";
    // std::cout << "    Choose an AirTracker sensor and calculate: radius of air it has purified, and level of AQI improvement.\n";
    //
    // std::cout << "4 - Evaluate an AirTracker's reliability (FR5)\n"; // GovernmentUser only
    // std::cout << "    Choose an AirTracker, view its calculated deviation from other nearby sensors, and decide whether to mark as unreliable.\n";
    //
    // std::cout << "5 - Evaluate a private individual's data submission (FR7)\n"; // GovernmentUser only
    // std::cout << "    View data submitted by an individual, and choose to accept or mark as unreliable.\n";
    //
    // std::cout << "6 - Share private data from personal sensor (FR6)\n"; // PrivateUser only ?
    // std::cout << "    Choose a file to upload, and request it be added to the dataset.\n";
    //
    // std::cout << "7 - View recent app performance metrics (FR9)\n";
    // std::cout << "    AirWatcher measures execution time for each algorithm ran, view the recent metrics here to visualise performance.\n";
}
