#include <stdio.h>
#include <vector>
#include <string>

float letterToGrade(std::string grade);

int main (int argc, char** argv) 
{
    std::vector<float> gradeVec;

    
    
    return 0;
}

float letterToGrade(std::string grade)
{
    float gradeFloat;

    if (grade.compare("A+") || grade.compare("A"))
    {
        gradeFloat = 4.0;
    } else if (grade.compare("A-"))
    {
        gradeFloat = 3.7;
    } else if (grade.compare("B+"))
    {
        gradeFloat = 3.3;
    } else if (grade.compare("B"))
    {
        gradeFloat = 3.0;
    } else if (grade.compare("B-"))
    {
        gradeFloat = 2.7;
    } else if (grade.compare("C+"))
    {
        gradeFloat = 2.3;
    } else if (grade.compare("C"))
    {
        gradeFloat = 2.0;
    } else if (grade.compare("C-"))
    {
        gradeFloat = 1.7;
    } else if (grade.compare("D+"))
    {
        gradeFloat = 1.3;
    } else if (grade.compare("D"))
    {
        gradeFloat = 1.0;
    } else if (grade.compare("F"))
    {
        gradeFloat = 0.0;
    } else
    {
        gradeFloat = -1;
    }

    return gradeFloat;
}
