// USMAN SAMI-545491
#include <iostream>
using namespace std;

int main() {
    int sales[5];
    int *p = sales;
    int a; //This int is used to validate entered values//
    int total=0;
    cout<<"Kindly enter 5 non negative values: "<<endl;
    // loop for taking values and validating //
    for (int i = 0; i < 5; i++){
        cout<<"Enter integer "<<i+1<<":";
        cin>>a;
        if(a<0){
            cout<<"Negative values are not acceptable!"<<endl;
            i--;
        }
        else{
            *(p+i)=a;
        }
    }
    // loop for displaying values and calulating the total //
    for (int i = 0; i < 5; i++){
        total+=*(p+i);
        cout<<*(p+i)<<"  ";
    }
    cout<<endl;
    cout<<"Total of sales = "<<total<<endl;

    *(p+2)+=2;
    total+=2;

    // loop for displaying updated values and calulating the total //
    cout<<"Updated Values:"<<endl;
    for (int i = 0; i < 5; i++){
        cout<<*(p+i)<<"  ";
    }
    cout<<endl;
    cout<<"Updated total of sales = "<<total;
    return 0;
}   
