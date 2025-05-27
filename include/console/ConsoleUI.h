//
// Created by Christopher Wilson on 27/05/2025.
//

#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <vector>

#include "models/users/User.h"
#include "models/users/UserTypeEnum.h"

enum class MenuAction {
    Quit,
    EvaluateAQIAverages,              // FR3
    CompareAQISimilarity,             // FR2
    CalculateAirTrackerImpact,        // FR4
    EvaluateAirTrackerReliability,    // FR5
    EvaluatePrivateSubmission,        // FR7
    SharePrivateData,                 // FR6
    ViewPerformanceMetrics            // FR9
};

struct MenuOption {
    MenuAction menu_action;
    string title;
    string description;
    vector<UserType> allowedRoles{};

    MenuOption(const MenuAction menu_action, const string& title, const string& description, const vector<UserType>& roles)
        : menu_action(menu_action), title(title), description(description), allowedRoles(roles) {}
};

class ConsoleUI
{
    User* authenticated_user = nullptr;

    vector<MenuOption> menuOptions = {
        {
            MenuAction::EvaluateAQIAverages,
            "Evaluate AQI averages (FR3)",
            "Specify an area and period of time, and view the mean air quality.",
            {UserType::Private, UserType::AirCleanerProvider, UserType::Government}
        },
        {
            MenuAction::CompareAQISimilarity,
            "Compare AQI similarity between sensors (FR2)",
            "Choose a sensor and rank all others based on similarity of air quality averages.",
            {UserType::Private, UserType::AirCleanerProvider, UserType::Government}
        },
        {
            MenuAction::CalculateAirTrackerImpact,
            "Calculate an AirTracker's air quality impact (FR4)",
            "Choose an AirTracker sensor and calculate: radius of air it has purified, and level of AQI improvement.",
            {UserType::Private, UserType::AirCleanerProvider, UserType::Government}
        },
        {
            MenuAction::EvaluateAirTrackerReliability,
            "Evaluate an AirTracker's reliability (FR5)",
            "Choose an AirTracker, view its calculated deviation from other nearby sensors, and decide whether to mark as unreliable.",
            {UserType::Government}
        },
        {
            MenuAction::EvaluatePrivateSubmission,
            "Evaluate a private individual's data submission (FR7)",
            "View data submitted by an individual, and choose to accept or mark as unreliable.",
            {UserType::Government}
        },
        {
            MenuAction::SharePrivateData,
            "Share private data from personal sensor (FR6)",
            "Choose a file to upload, and request it be added to the dataset.",
            {UserType::Private}
        },
        {
            MenuAction::ViewPerformanceMetrics,
            "View recent app performance metrics (FR9)",
            "AirWatcher measures execution time for each algorithm ran, view the recent metrics here to visualise performance.",
            {UserType::Private, UserType::AirCleanerProvider, UserType::Government}
        },
        {
            MenuAction::Quit,
            "Quit",
            "Exit the application.",
            {UserType::Private, UserType::AirCleanerProvider, UserType::Government}
        }
    };

    MenuAction select_action() const;

public:
    void run();
};


#endif //CONSOLEUI_H
