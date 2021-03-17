// bmioo.cpp : by Hristian
#include <iostream>
#include <string>
#include <stdlib.h> /*for system()*/
#include "clearScreen.h"
#include "bmioo.h"
using namespace std;

//prototype section

//
int main() {
    bmi myBmi;

    do {
        clearScreen();
        myBmi.printHeader();
        myBmi.setMeasurementSystem();
        myBmi.getHeightAndWeight();
        myBmi.calculateBmi();
        myBmi.printResults();

        cout << endl << "Enter y if you want to calculate another BMI value, or x to exit: ";
        cin >> myBmi.calculate_bmi_again;

    } while (myBmi.calculate_bmi_again == 'y' || myBmi.calculate_bmi_again == 'Y');
}
