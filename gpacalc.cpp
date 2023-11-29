// Includes
#include <iomanip>
#include <iostream>
#include <string>

// Predefining Functions
float gradeInput();
float gradeToGpa(std::string letter);
float average(float grades[], int gradec);

// Main Function
int main (int argc, char *argv[]) {

    // Number of Grades
    int numberOfGrades;
    std::cout << "How many grades would you like to calculate for: ";
    std::cin >> numberOfGrades;

    // Initialize Array
    float gradesArr[numberOfGrades];

    // Get Grade Values
    for (int i = 0; i < numberOfGrades; i++) {
        std::cout << "Grade #" << i + 1 << "\n";
        float gpaVal {gradeInput()};
        gradesArr[i] = gpaVal;
    }

    // Average
    float ave = average(gradesArr, numberOfGrades);

    // Final Output
    std::cout << "Your GPA is " << std::fixed << std::setprecision(1) << ave << std::endl;

    return 0;
}

// Side Functions
float gradeInput() {

    float gpaVal {-1};
    std::string letter;

    do {
        std::cout << "Please enter a valid grade: ";
        std::cin >> letter;
        gpaVal = gradeToGpa(letter);
    } while (gpaVal == -1);

    return gpaVal;
}

float gradeToGpa(std::string letter) {

    float gpaVal;

    // Idk how to make this more efficient
    if (letter.compare("A") == 0 || letter.compare("A+") == 0) {
        gpaVal = 4;
    } else if (letter.compare("A-") == 0) {
        gpaVal = 3.7;
    } else if (letter.compare("B+") == 0) {
        gpaVal = 3.3;
    } else if (letter.compare("B") == 0) {
        gpaVal = 3;
    } else if (letter.compare("B-") == 0) {
        gpaVal = 2.7;
    } else if (letter.compare("C+") == 0) {
        gpaVal = 2.3;
    } else if (letter.compare("C") == 0) {
        gpaVal = 2;
    } else if (letter.compare("C-") == 0) {
        gpaVal = 1.7;
    } else if (letter.compare("D+") == 0) {
        gpaVal = 1.3;
    } else if (letter.compare("D") == 0) {
        gpaVal = 1;
    } else if (letter.compare("F") == 0) {
        gpaVal = 0;
    } else {
        gpaVal = -1;
    }

    return gpaVal;
}

float average(float *grades, int gradec) {

    float ave {0};

    for (int i = 0; i < gradec; i++) {
        ave += grades[i];
    }

    ave /= gradec;

    return ave;
}
