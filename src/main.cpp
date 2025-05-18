#include <iostream>
using namespace std;
#include "CSVLoader.h"
int main(){
    cout << "Hello World!" << endl;

    CSVLoader& loader = CSVLoader::Instance();
    return 0;
}