// Usman Sami - 545491
#include <iostream>
using namespace std;

int main()
{
    int n;
    // taking the input from user for number of marks 
    cout << "Enter number of marks (1-10): ";
    cin >> n;

    int *marks = new int[n];
    // taking marks as input
    cout << "Enter " << n << " marks: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(marks + i);
    }

    int *newMarks = new int[n + 1];
    // taking new mark as input
    for (int i = 0; i < n; i++)
    {
        *(newMarks + i) = *(marks + i);
    }
    cout << "Enter the new mark: ";
    cin >> *(newMarks + n);

    delete[] marks;

    marks = newMarks;
    n = n + 1;

    // displaying all the marks
    cout << "All marks: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(marks + i) << " ";
    }
    delete[] marks;
    marks = nullptr;

    return 0;
}
