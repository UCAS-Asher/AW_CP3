//AW, Calculator Menu Options

#include <iostream>
#include <limits>

using namespace std;

enum Menu{
    Add = 1,
    Subtract,
    Multiply,
    Divide,
    Exit 
};

pair<double,double> get_num(){
    double num1;
    double num2;
    cout << "1st Number: ";
    if(cin >> num1){

    }
    else{
        cout << "Only put a Number!" << endl << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        pair<double,double> nums = get_num();
        double num1 = nums.first;
        double num2 = nums.second;
        return {num1, num2};
    }
    cout << "2nd Number: ";
    cin >> num2;
    if(cin >> num1){

    }
    else{
        cout << "Only put a Number!" << endl << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        pair<double,double> nums = get_num();
        double num1 = nums.first;
        double num2 = nums.second;
        return {num1, num2};
    }
    return {num1, num2};
}

void addition(){
    pair<double,double> nums = get_num();
    double num1 = nums.first;
    double num2 = nums.second;
    cout << "The Sum is: " << num1 + num2 << endl << endl;
}

void subtraction(){
    pair<double,double> nums = get_num();
    double num1 = nums.first;
    double num2 = nums.second;
    cout << "The Diffrence is: " << num1-num2 << endl << endl;
}

void multiplication(){
    pair<double,double> nums = get_num();
    double num1 = nums.first;
    double num2 = nums.second;
    cout << "The Product is: " << num1*num2 << endl << endl;
}

void division(){
    pair<double,double> nums = get_num();
    double num1 = nums.first;
    double num2 = nums.second;
    cout << "The Quotient is: " << num1/num2 << endl <<  endl;
}

int main(){
    int choice;
    cout << "Calculator Choices" << endl << "1. Add" << endl << "2. Subtract" << endl << "3. Multiply" << endl << "4. Divide" << endl << "5. Exit" << endl << "Choose a  Number: ";
    cin >> choice;

    if(choice == Menu::Add)
        addition();
    else if(choice == Menu::Subtract)
        subtraction();
    else if(choice == Menu::Multiply)
        multiplication();
    else if(choice == Menu::Divide)
        division();
    else if(choice  == Menu::Exit)
        cout << "Program End" << endl;
    else
        cout << "Not an Option" << endl;
    main();


    return 0;
}