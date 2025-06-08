//
// Created by Christopher Wilson on 27/05/2025.
//

#include "console/AuthManager.h"

#include <iostream>

#include "models/users/GovernmentUser.h"
#include "dataAccess/CSVLoader.h"
#include "models/users/AirCleanerProviderUser.h"

User* AuthManager::login() const
{
    UserType userType = select_user_type();

    switch (userType)
    {
        case UserType::Government:
            return GovernmentUser::getInstance();

        case UserType::Private:
        {
            std::cout << "Enter your login (e.g. User0): " << std::flush;
            std::string login;
            std::cin >> login;

            const CSVLoader& loader = CSVLoader::Instance();
            const vector<PrivateUser> users = loader.getUsers();

            for (const PrivateUser& user : users)
            {
                if (user.getId() == login)
                {
                    return new PrivateUser();
                }
            }
        }

        case UserType::AirCleanerProvider:
        {
            std::cout << "Enter your login (e.g. Provider0): " << std::flush;
            std::string login;
            std::cin >> login;

            const CSVLoader& loader = CSVLoader::Instance();
            const vector<AirCleanerProviderUser> providers = loader.getProviders();

            for (const AirCleanerProviderUser& provider : providers)
            {
                if (provider.getId() == login)
                {
                    return new AirCleanerProviderUser();
                }
            }
        }
    }
    return nullptr;
}

UserType AuthManager::select_user_type() const
{
    while (true)
    {
        std::cout << "Are you:\n";
        std::cout << "1 - A Private user\n";
        std::cout << "2 - A Government employee\n";
        std::cout << "3 - An Air Cleaner Provider\n";
        std::cout << "Please select a number from above: ";
        std::cout << std::flush;

        int choice = 0;
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                return UserType::Private;
            case 2:
                return UserType::Government;
            case 3:
                return UserType::AirCleanerProvider;
            default:
                std::cout << "Invalid input. Please enter 1, 2, or 3.\n";
                break;
        }
    }
}
