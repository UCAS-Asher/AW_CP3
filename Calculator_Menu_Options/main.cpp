//AW, Calculator Menu Options

#include <iostream>

using namespace std;

enum Menu{
    Addition = 1,
    Subtraction,
    Multiplication,
    Division 
};

int get_num(){
    int num1;
    int num2;
    cout << "1st Number: ";
    cin >> num1;
    if(!cin)
        num1, num2 = get_num();
        int num1 = nums.first;
        int num2 = nums.second

    cout << "2nd Number: ";
    cin >> num2;

    return {num1, num2};
}

void addition(){
    cout << "1st Number: ";
    int num1;
    cin >> num1;
    cout << "2nd Number: ";
    int num2;
    cin >> num2;

}

void subtraction(){

}

void multiplication(){

}

void division(){

}

int main(){
    int choice;
    cout << "Calculator Choices" << endl << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multiplication" << endl << "4. Division" << endl << "Select: ";
    cin >> choice;

    if(choice == Menu::Addition)
        addition();
    else if(choice == Menu::Subtraction)
        subtraction();
    else if(choice == Menu::Multiplication)
        multiplication();
    else if(choice == Menu::Division)
        division();
    else
        cout << "Not an Option" << endl;
    main();


    return 0;
}