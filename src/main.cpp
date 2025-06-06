#include <iostream>
using namespace std;
#include "dataAccess/CSVLoader.h"
#include "console/AuthManager.h"
#include "console/ConsoleUI.h"

int main() {
    cout << "Hello World!" << endl;

    ConsoleUI consoleUI;
    consoleUI.run();  // Starts interactive loop
    return 0;

    CSVLoader& loader = CSVLoader::Instance();
    return 0;
}