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
    
    while(true){
        cout << "1st Number: ";
        
        if(!(cin >> num1)){
            cout << "Only put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        cout << "2nd Number: ";
        
        if(!(cin >> num2)){
            cout << "Only put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        return {num1, num2};
    }
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
    
    while(!(cin >> choice)){
        cout << "Put a Number!" << endl << endl;
        cin.clear();
        cin.ignore();
        cout << "Calculator Choices" << endl << "1. Add" << endl << "2. Subtract" << endl << "3. Multiply" << endl << "4. Divide" << endl << "5. Exit" << endl << "Choose a  Number: ";
    }

    if(choice == Menu::Add){
        addition();
        main();
    }
    else if(choice == Menu::Subtract){
        subtraction();
        main();
    }
    else if(choice == Menu::Multiply){
        multiplication();
        main();
    }
    else if(choice == Menu::Divide){
        division();
        main();
    }
    else if(choice  == Menu::Exit)
        cout << "Program End" << endl;
    else{
        cout << "Not an Option" << endl;
        main();
    }

    return 0;
}