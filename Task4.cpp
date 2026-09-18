// Usman Sami - 545491
#include <iostream>
using namespace std;

// function to calculate total marks of a student
int totalMarks(int **marks, int r, int numberOfSubjects)
{
    int total = 0;
    for (int c = 0; c < numberOfSubjects; c++)
    {
        total += *(*(marks + r) + c);
    }
    return total;
}

int main()
{
    int numberOfStudents;
    int numberOfSubjects;
    // taking inputs of students and subjects from the user and validating
    do
    {
        cout << "Please enter the number of students: ";
        cin >> numberOfStudents;
        if (numberOfStudents < 0)
        {
            cout << "Number of students cannot be negative!" << endl;
        }
    } while (numberOfStudents < 0);

    do
    {
        cout << "Please enter the number of Subjects: ";
        cin >> numberOfSubjects;
        if (numberOfSubjects < 0)
        {
            cout << "Number of Subjects cannot be negative!" << endl;
        }
    } while (numberOfSubjects < 0);

    // allocating rows and columns by numberOfStudents and numberOfSubjects
    int **marks = new int *[numberOfStudents];
    for (int i = 0; i < numberOfStudents; i++)
    {
        marks[i] = new int[numberOfSubjects];
    }

    // taking inputs from the user
    for (int r = 0; r < numberOfStudents; r++)
    {
        cout << "==== Marks of student " << r + 1 << " ==== " << endl;
        for (int c = 0; c < numberOfSubjects; c++)
        {
            cout << "Enter marks of subject " << c + 1 << " : ";
            cin >> *(*(marks + r) + c);
        }
    }

    // displaying the output
    for (int r = 0; r < numberOfStudents; r++)
    {
        for (int c = 0; c < numberOfSubjects; c++)
        {
            cout << *(*(marks + r) + c) << "  ";
        }
        cout << endl;
    }

    // determining first student total and then comparing with other students
    int totalOfStudent1 = totalMarks(marks, 0, numberOfSubjects);
    int highestTotal = totalOfStudent1;
    cout << "Total marks of student 1 : " << totalOfStudent1 << endl;
    int indexOfHighest = 0;

    for (int r = 1; r < numberOfStudents; r++)
    {
        int total = totalMarks(marks, r, numberOfSubjects);
        cout << "Total marks of student " << r + 1 << ": "
             << total << endl;

        if (total > highestTotal)
        {
            highestTotal = total;
            indexOfHighest = r + 1;
        }
    }

    // displaying the best student and best total
    cout << "Top Student is " << indexOfHighest << endl;
    cout << "His total marks are " << highestTotal << endl;

    // deleting all the dynamic allocation
    for (int i = 0; i < numberOfStudents; i++)
    {
        delete[] marks[i];
    }

    delete[] marks;
    marks = nullptr;

    return 0;
}