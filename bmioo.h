class bmi {
public:
// Member functions
    //****************************************
    void printHeader() {
        std::cout << std::endl << "BMI Calculator. https://github.com/hristian-carabulea/bmioo" << std::endl
             << "Data source: https://www.calculator.net/bmi-calculator.html." << std::endl;
        std::cout << "************************************************************" << std::endl;
        std::cout << "For most adults, an ideal BMI is in the 18.5 to 24.9 range. If your BMI is:"  << std::endl
             << "   below   16.0,           you are severely thin." << std::endl
             << "   16.0 to less than 17,   you are moderately thin." << std::endl
             << "   17.0 to less than 18.5, you are mildly thin." << std::endl
             << "   18.5 to less than 25,   you are in the healthy weight range." << std::endl
             << "   25.0 to less than 30,   you are in the overweight range." << std::endl
             << "   30.0 to less than 35,   you are in the obese class I." << std::endl
             << "   35.0 to less than 40,   you are in the obese class II." << std::endl
             << "           40 and above,   you are in the obese class III." << std::endl;
        std::cout << "************************************************************" << std::endl;
        std::cout << std::endl << "Let us calculate your BMI (Body Mass Index)." ;
    };
    //****************************************
    void setMeasurementSystem() {
        while(true) {
            std::cout << std::endl << "Enter m (for Metric values), u (for US System), or x to exit: ";
            std::cin >> measurementSystem;
            if (measurementSystem == 'm' || measurementSystem == 'u') break;
            else if (measurementSystem == 'x') {
                exit(EXIT_SUCCESS);
            }
        }
    };
    //****************************************
    void getHeightAndWeight() {
        if (measurementSystem == 'm') {
            inputMessage = "Enter your height in cm, format 999.9: ";
            height = checkFloat(inputMessage);
            inputMessage = "Enter your weight in kg, format 999.9: ";
            weight= checkFloat(inputMessage);
        //break;
        }
        else if (measurementSystem == 'u') {
            inputMessage = "Enter your height in inches, format 999.9: ";
            height = checkFloat(inputMessage);
            inputMessage = "Enter your weight in pounds, format 999.9: ";
            weight= checkFloat(inputMessage);
            height = convertInchToCm(height);
            weight = convertPoundsToKg(weight);
        //break;
        }
    };
    //****************************************
    void calculateBmi () {
        bmiValue = (weight * 10000) / (height * height);
    };
    //******************************************************************
    void printResults() {

        std::cout.precision(2);
        std::cout << std::endl;
        std::printf("Your BMI is %.2lf.", bmiValue);

        if (bmiValue < 16) {
            std::cout << " You are severly thin." << std::endl;
        }
        else if (bmiValue >= double(16) && bmiValue < double(17)) {
            std::cout << " You are moderately thin." << std::endl;
        }
        else if (bmiValue >= 17.0 && bmiValue < 18.5) {
            std::cout << " You are mildly thin." << std::endl;
        }
        else if (bmiValue >= 18.5 && bmiValue < 25) {
            std::cout << " You have a normal weight." << std::endl;
        }
        else if (bmiValue >= 25.0 && bmiValue < 30) {
            std::cout << " You are overweight." << std::endl;
        }
        else if (bmiValue >= 30 && bmiValue < 35) {
            std::cout << " You are obese class I." << std::endl;
        }
        else if (bmiValue >= double(35) && bmiValue < double(40)) {
            std::cout << " You are obese class II." << std::endl;
        }
        else if (bmiValue >= 40) {
            std::cout << "You are obese class III." << std::endl;
        }
    };
    //****************************************
    double convertInchToCm (double inchAmount) {
        double cmAmount = inchAmount * 2.54;
        return cmAmount;
    };
    //****************************************
    double convertPoundsToKg (double lbsAmount) {
        double kgAmount = lbsAmount * 0.453592;
        return kgAmount;
    };
    //*****************************
    // Takes in an instructions string requesting a float number, and
    // calls function isNumber 
    double checkFloat (std::string message) {
        std::string inputNumString;
        double numRead;
        
        while (true) {
            std::cout << message;
            std::cin >> inputNumString;

            if (isFloat(inputNumString)) {
                numRead = stod(inputNumString);
                break;
            }
        }
        return numRead;
    };
    //******************************************************************
    bool isFloat(std::string str) {
        
        int dotCount = 0, i = 0;
        for (i = 0; i < str.length(); i++) {
            if (str[i] == '.') {
                dotCount++;
                if (dotCount > 1) {
                    return false;
                }
            }
            else if ( isdigit(str[i]) && (dotCount > 1) ) {
                return false;
            }
            else if (isdigit(str[i]) == false) {
                return false;        
            }
        }
        return true;
    };
    //******************************************************************
    int checkInteger (std::string message) {
        std::string inputNumString;
        int numRead;
        
        while (true) {
            std::cout << message;
            std::cin >> inputNumString;

            if (isInteger(inputNumString)) {
                numRead = stoi(inputNumString);
                break;
            }
        }
        return numRead;
    };
    //******************************************************************
    bool isInteger(std::string str) {
        for (int i = 0; i < int(str.length()); i++)
            if (isdigit(str[i]) == false)
                return false;
        return true;
    };
    //******************************************************************
    // Data members
    double bmiValue = 0.00;
    double weight = 0.00;
    double height = 0.00;
    char calculate_bmi_again = 'n';
    char measurementSystem = 'm';
    std::string inputMessage = " ";
    std::string message = " ";
//******************************************************************
private:
//Member functions

//Data Members

};