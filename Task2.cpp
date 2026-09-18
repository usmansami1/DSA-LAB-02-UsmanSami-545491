// Usman Sami-545491    
#include <iostream>
using namespace std;

int main() {
    int numberOfStudents;
    // taking the number of students from the teacher and validating
    cout<<"Enter the number of students: ";
    cin>>numberOfStudents;
    while(numberOfStudents<0){
        
        if(numberOfStudents<0){
            cout<<"Number of students cannot be negative!"<<endl;
        }
        cout<<"Enter the number of students: ";
        cin>>numberOfStudents;
}
    int *marks = new int[numberOfStudents];
    // Using loop to take the marks from user
    for(int i=0; i<numberOfStudents; i++){
        cout<<"Enter the marks of Student "<<i+1<<" : ";
        cin>>*(marks+i);
    }
    cout<<endl;
    double total = 0;
    double average = 0;
    int marks50 = 0;

    // using loop to calculate all the required things
    for (int i = 0; i < numberOfStudents; i++){
        cout<<*(marks+i)<<"  ";
        total+=*(marks+i);

        if (*(marks+i)>=50){
            marks50++;
        }
        
    }
    cout<<endl;
    average = total/numberOfStudents;
    
    cout<<"Total of marks = "<<total<<endl;
    cout<<"Average of marks = "<<average<<endl;
    cout<<"Marks >= 50 = "<<marks50<<endl;

    delete[] marks;
    marks = nullptr;
    return 0;
}   