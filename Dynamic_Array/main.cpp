// AW Dynamic Array

#include <iostream>
#include <algorithm> // For std::find
#include <iterator>
#include <string>
using namespace std;

int capacity = 5;
string* colors = new string[capacity];

int entries = 0;



void program(){
    
}


int main(){
    int choice;
    cout << "Choices" << endl << "1. Start Program" << endl << "2. Exit" << endl << "Choose a Number: ";
    cin  >> choice;
    cout << endl;

    if(choice == 1){
        program();
    }
    else if(choice == 2){
        cout << "Program End";
    }
    else{
        cout << "Not an Option" << endl;
    }
    
    
    return 0;
}