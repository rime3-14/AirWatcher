#include <iostream>
using namespace std;
#include "dataAccess/CSVLoader.h"
int main(){
    cout << "Hello World!" << endl;

    CSVLoader& loader = CSVLoader::Instance();
    return 0;
}