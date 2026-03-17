#include <iostream>
#include <iomanip>

double convertToKg(double pounds) {
    return pounds * 0.45;  // conversion rate given
}

double convertToMeters(int feet, int inches) {
    int totalInches = feet * 12 + inches;
    return totalInches * 0.025;  // conversion rate given
}

double calculateBMI(double weightKg, double heightM) {
    return weightKg / (heightM * heightM);
}

std::string getBMICategory(double bmi) {
    if (bmi < 18.5)
    {
        return "Underweight";
    }

    else if (bmi < 25)
    {
        return "Normal Weight";
    }

    else if (bmi < 30)
    {
        return "Overweight";
    }

    else
    {
        return "Obese";
    }
}

int main() 
{
    double bmi, weight, height;
    int feet, inches;
    char again = 'y';

    while (again == 'y') 
    {
        std::cout << "Enter Your Height in Feet and Inches Below... " << std::endl;
        std::cout << "Feet: ";
        std::cin >> feet;

        while (feet < 0) 
        {
            std::cout << "Invalid input for feet. Input 0 or a positive number for feet: ";
            std::cin >> feet;
        }

        std::cout << "Inches: ";
        std::cin >> inches;

        while (inches < 0)
        {
            std::cout << "Invalid input for inches. Input 0 or a positive number for inches: ";
            std::cin >> inches;
        }

        while (inches >= 12)
        {
            inches -= 12;
            feet += 1;
        }

        if (feet == 0 && inches == 0)
        {
            std::cout << "You can't have a total height amounting to 0 inches. Cannot compute BMI..." << std::endl;
            return 1;
        }

        std::cout << "Enter your weight (pounds): ";
        std::cin >> weight;

        while (weight <= 0)
        {
            std::cout << "Weight must be greater than 0. Input new value for weight: ";
            std::cin >> weight;
        }

        // Converting & Calculating BMI functions
        weight = convertToKg(weight);
        height = convertToMeters(feet, inches);
        bmi = calculateBMI(weight, height);

        std::cout << "Your BMI is: " << std::fixed << std::setprecision(1) << bmi << std::endl;
        std::cout << "Category: " << getBMICategory(bmi) << std::endl;

        std::cout << "Do you want to calculate another BMI (y/n)? ";
        std::cin >> again;

        // Checks if input is valid
        while (again != 'y' && again != 'n') 
        {
            std::cout << "Invalid answer. Type 'y' to calculate another BMI and 'n' if you want to stop: ";
            std::cin >> again;
        }

        // Separates each calculation for organization purposes
        if (again == 'y')
        {
            std::cout << std::endl;
        }
    }
    return 0;
}
