// Includes
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// Data Types
class Grade
{
    // Private Properties
private:
    std::string courseName;
    std::string letterGrade;
    float numberGrade;
    float units;
    float gradeUnits;

    // Public Methods
public:
    Grade(std::string courseName, std::string letterGrade, float units):
        courseName(courseName),
        letterGrade(letterGrade),
        units(units)
    {
        numberGrade = gradeToNum(letterGrade);
        gradeUnits = units * numberGrade;
    }

    void displayGrade()
    {
        std::cout << "Course: " << courseName 
            << ", Letter Grade: " << std::fixed << std::setprecision(1) << letterGrade
            << ", Number Grade: " << std::fixed << std::setprecision(1) << numberGrade
            << ", Units: " << units
            << "\n";
    }

    void changeGrade(std::string newGrade)
    {
        letterGrade = newGrade;
        numberGrade = gradeToNum(newGrade);
    }

    float getNumberGrade()
    {
        return numberGrade;
    }

    std::string getName()
    {
        return courseName;
    }

private:
    float gradeToNum(std::string letter)
    {

        float gpaVal;

        // Idk how to make this more efficient
        if (letter.compare("A") == 0 || letter.compare("A+") == 0)
        {
            gpaVal = 4.0;
        } else if (letter.compare("A-") == 0)
        {
            gpaVal = 3.7;
        } else if (letter.compare("B+") == 0)
        {
            gpaVal = 3.3;
        } else if (letter.compare("B") == 0)
        {
            gpaVal = 3;
        } else if (letter.compare("B-") == 0)
        {
            gpaVal = 2.7;
        } else if (letter.compare("C+") == 0)
        {
            gpaVal = 2.3;
        } else if (letter.compare("C") == 0)
        {
            gpaVal = 2;
        } else if (letter.compare("C-") == 0)
        {
            gpaVal = 1.7;
        } else if (letter.compare("D+") == 0)
        {
            gpaVal = 1.3;
        } else if (letter.compare("D") == 0)
        {
            gpaVal = 1;
        } else if (letter.compare("F") == 0)
        {
            gpaVal = 0;
        } else
        {
            gpaVal = -1;
        }

        return gpaVal;
    }
};

// Predefining Functions
int mainMenu();
int menuInput(int min, int max);
void displayGrades(std::vector<Grade> &gradeArr);
void addClass(std::vector<Grade> &gradeArr);
void removeClass(std::vector<Grade> &gradeArr);
void editClassCheck(std::vector<Grade> &gradeArr);
void editClass(Grade &course);
int editClassMenu();

// Main Function
int main(int argc, char *argv[])
{

    std::cout << "Welcome to a GPA Calculating Program\n";
    int choice;

    std::vector<Grade> gradeArr;

    do
    {
        std::cout << std::endl;
        choice = mainMenu();
        if (choice == 1)
        {
            displayGrades(gradeArr);
        } else if (choice == 2)
        {
            addClass(gradeArr);
        } else if (choice == 3)
        {
            removeClass(gradeArr);
        } else if (choice == 4)
        {
            editClassCheck(gradeArr);
        }

    } while (choice != 0);

    return 0;
}

int mainMenu()
{

    // Print Menu
    std::cout << "0. Exit Program\n"
        << "1. Display Classes\n" 
        << "2. Add Class\n" 
        << "3. Remove Class\n"
        << "4. Edit Class\n"
        << "5. Calculate Average\n";

    return menuInput(0, 5);
}

int menuInput(int min, int max)
{

    int choiceInt;
    bool loop {true};

    while (loop)
    {
        std::cout << "Enter a valid option: ";
        std::cin >> choiceInt;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
        } else if (choiceInt >= min && choiceInt <= max)
        {
            std::cout << std::endl;
            loop = false;
        }
    }

    return choiceInt;
}

void displayGrades(std::vector<Grade> &gradeArr)
{
    if (gradeArr.size() > 0)
    {
        for (int i {0}; i < gradeArr.size(); i++)
        {
            gradeArr[i].displayGrade();
        }
    } else
    {
        std::cout << "There are no courses." << "\n";
    }
}

void addClass(std::vector<Grade> &gradeArr)
{
    std::string courseName, letterGrade;
    float units;
    std::cout << "Please add a course name: ";
    std::cin >> courseName;

    for (int i = 0; i < gradeArr.size(); i++)
    {
        if (courseName.compare(gradeArr[i].getName()) == 0)
        {
            std::cout << "That course name is already in use.\n";
            return;
        }
    }

    std::cout << "Please add letter grade: ";
    std::cin >> letterGrade;
    std::cout << "Please add course units: ";
    std::cin >> units;

    Grade tempGrade {courseName, letterGrade, units};
    gradeArr.push_back(tempGrade);
}

void removeClass(std::vector<Grade> &gradeArr)
{
    std::string courseName;
    std::cout << "Please choose a course to remove: ";
    std::cin >> courseName;

    for (int i = 0; i < gradeArr.size(); i++)
    {
        if (courseName.compare(gradeArr[i].getName()) == 0)
        {
            gradeArr.erase(gradeArr.begin() + i);
            std::cout << "The course, " << courseName << ", has successfully been removed.\n";
            return;
        }
    }

    std::cout << "No such course has been found.\n";
}

void editClassCheck(std::vector<Grade> &gradeArr)
{
    std::string courseName;
    std::cout << "Please choose a course to edit: ";
    std::cin >> courseName;

    for (int i = 0; i < gradeArr.size(); i++)
    {
        if (courseName.compare(gradeArr[i].getName()) == 0)
        {
            editClass(gradeArr[i]);
            return;
        }
    }

    std::cout << "No such course has been found.\n";
}

void editClass(Grade &course)
{
    int choice;

    do 
    {
        std::cout << std::endl;
        choice = editClassMenu();
        if (choice == 1)
        {
            
        }

    } while (choice != 0);
}

int editClassMenu()
{
    std::cout << "0. Return to main menu\n"
        << "1. View selected course\n"
        << "2. Edit course grade\n"
        << "3. Edit course units\n";

    return menuInput(0, 3);
}
