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

    cout << "Welcome to AirWatcher\n";

    cout << "You can use this tool to access different information regarding air quality of the area.\n";
    cout << "What would you like to do?\n";

    vector<const MenuOption*> availableOptions;

    for (const auto& option : menuOptions) {
        if (find(option.allowedRoles.begin(), option.allowedRoles.end(), role) != option.allowedRoles.end()) {
            availableOptions.push_back(&option);
        }
    }

    for (int i = 0; i < availableOptions.size(); i++) {
        cout << i + 1 << " - " << availableOptions[i]->title << ": " << availableOptions[i]->description << "\n";
    }

    cout << "(Note: AQI = Air Quality Index)\n";
    cout << "Please select a number from above: ";
    cout << flush;

    int choice;
    cin >> choice;
    if (choice < 1 || choice > availableOptions.size()) {
        throw runtime_error("Invalid selection");
    }

    return availableOptions.at(choice - 1)->menu_action;
}

void ConsoleUI::run()
{
    // Log user in
    AuthManager authManager;
    authenticated_user = authManager.login();

    if (authenticated_user == nullptr)
        throw runtime_error("User not authenticated");

    // Perform main application loop
    MenuAction action;
    do {
        action = select_action();

        switch (action)
        {
            case MenuAction::Quit:
                cout << "Exiting App" << endl;
            break;
            case MenuAction::EvaluateAQIAverages:
                cout << "Not yet implemented" << endl;
            break;
            case MenuAction::CompareAQISimilarity:
                cout << "Not yet implemented" << endl;
            break;
            case MenuAction::CalculateAirTrackerImpact:
                cout << "Not yet implemented" << endl;
            break;
            case MenuAction::EvaluateAirTrackerReliability:
                cout << "Not yet implemented" << endl;
            break;
            case MenuAction::EvaluatePrivateSubmission:
                cout << "Not yet implemented" << endl;
            break;
            case MenuAction::SharePrivateData:
                cout << "Not yet implemented" << endl;
            break;
            case MenuAction::ViewPerformanceMetrics:
                cout << "Not yet implemented" << endl;
            break;
        }
    } while (action != MenuAction::Quit);


    // cout << "1 - Evaluate AQI averages (FR3)\n";
    // cout << "    Specify an area and period of time, and view the mean air quality\n";
    //
    // cout << "2 - Compare AQI similarity between sensors: (FR2)\n";
    // cout << "    Choose a sensor and rank all others based on similarity of air quality averages.\n";
    //
    // cout << "3 - Calculate an AirTracker's impact on air quality (FR4)\n";
    // cout << "    Choose an AirTracker sensor and calculate: radius of air it has purified, and level of AQI improvement.\n";
    //
    // cout << "4 - Evaluate an AirTracker's reliability (FR5)\n"; // GovernmentUser only
    // cout << "    Choose an AirTracker, view its calculated deviation from other nearby sensors, and decide whether to mark as unreliable.\n";
    //
    // cout << "5 - Evaluate a private individual's data submission (FR7)\n"; // GovernmentUser only
    // cout << "    View data submitted by an individual, and choose to accept or mark as unreliable.\n";
    //
    // cout << "6 - Share private data from personal sensor (FR6)\n"; // PrivateUser only ?
    // cout << "    Choose a file to upload, and request it be added to the dataset.\n";
    //
    // cout << "7 - View recent app performance metrics (FR9)\n";
    // cout << "    AirWatcher measures execution time for each algorithm ran, view the recent metrics here to visualise performance.\n";
}
