// Usman Sami-545491   
#include <iostream>
using namespace std;

// defining functions for branchtotal and daytotal
int branchTotal(int (*rowPtr)[3], int r){
    int total=0;
    for(int c=0;c<3;c++){
        total += *(*(rowPtr+r)+c);
    }
    return total;
}

int dayTotal(int(*rowPtr)[3], int c){
    int total=0;
    for(int r=0;r<2;r++){
        total += *(*(rowPtr+r)+c);
    }
    return total;
}

int main() {
    int sales[2][3];
    int (*rowPtr)[3] = sales;
    int a;
    // loop for taking elements from the user and validating it
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout<<"Enter element "<<c+1<<" of row "<<r+1<<" : ";
            cin>>a;
        if(a<0){
            cout<<"Negative values are not acceptable!"<<endl;
            c--;
        }
        else{
            *(*(rowPtr+r)+c) = a;
        }
        }
    }
    // loop for displaying the values
    for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout<<*(*(rowPtr+r)+c)<<"  ";
        }
        cout<<endl;
    }
    // calling the functions to calculate the totals
    cout<<"Total for branch 1 = "<<branchTotal(rowPtr,0)<<endl;
    cout<<"Total for branch 2 = "<<branchTotal(rowPtr,1)<<endl;
    cout<<"Total for day 1 = "<<dayTotal(rowPtr,0)<<endl;
    cout<<"Total for day 2 = "<<dayTotal(rowPtr,1)<<endl;
    cout<<"Total for day 3 = "<<dayTotal(rowPtr,2)<<endl;

    return 0;
}