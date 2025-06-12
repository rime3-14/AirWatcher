//
// Created by Christopher Wilson on 27/05/2025.
//

#include "console/ConsoleUI.h"

#include <iostream>

void ConsoleUI::run()
{
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

        switch (action)
        {
            case MenuAction::EvaluateAQIAverages:
                std::cout << "===== Evaluate AQI Averages: ====\n";
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::CompareAQISimilarity:
                std::cout << "==== Compare AQI Similarity: ====\n";
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::CalculateAirTrackerImpact:
                std::cout << "==== Calc AirTracker Impact: ====\n";
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::EvaluateAirTrackerReliability:
                std::cout << "== Eval AirTracker Reliability: =\n";
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::EvaluatePrivateSubmission:
                std::cout << "==== Eval Private Submission: ===\n";
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::SharePrivateData:
                std::cout << "====== Share Private Data: ======\n";
                std::cout << "Not yet implemented" << std::endl;
            break;
            case MenuAction::ViewPerformanceMetrics:
                std::cout << "==== View Performance Metrics: ===\n";
                std::cout << "Not yet implemented" << std::endl;
            break;
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

    for (int i = 0; i < availableOptions.size(); i++) {
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

        if (choice < 1 || choice > availableOptions.size()) {
            std::cout << "Invalid input. Please enter a number from 1 to " << availableOptions.size() << ".\n";
            continue;
        }

        return availableOptions.at(choice - 1)->menu_action;
    }
}