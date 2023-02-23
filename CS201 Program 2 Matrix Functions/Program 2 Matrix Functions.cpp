// Tom Steinman
//  CS201-0005
//  Program 2 Matrix Functions

#include "Matrix.h"

using namespace std;

string userMenuChoice;

int main() {
    while (true) {
        cout << "Enter the type of input to use:" << endl;
        cout << "0 - File" << endl;
        cout << "1 - Use set values" << endl;
        cout << "Enter your choice: ";
        cin >> userMenuChoice;
        if (userMenuChoice != "0" && userMenuChoice != "1") {
            cout << "Please choose options 0 or 1" << endl;
            continue;
        }
        else if (userMenuChoice == "1") {
            menuChoice1();
            continue;
        }
        else if (userMenuChoice == "0") {
            menuChoice2();
        }
    }
}





/*
    ifstream inFile;
    inFile.open("text.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file\n";
        return 1;
    }
    */