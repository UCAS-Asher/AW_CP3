// AW Dynamic Array

#include <iostream>
#include <algorithm> // For std::find
#include <iterator>
using namespace std;

int capacity = 5;
string* sanity = new string[capacity];
int entries = 0;

void program(){
    while(true){
            cout << "Color: ";
            cin >> sanity[entries];
            if () break;
            entries++;
            if(entries == capacity){
                capacity += 1;
                string* temp = new string[capacity];
                for(int i = 0; i < entries; i++)
                    temp[i] = sanity[i];
                delete[] sanity;
                sanity = temp;
            }
        }
    

    for(int i = 0; i < entries; i++){
        cout << sanity[i] << endl;// Delete after done using or you get memory leak
         
    }
    delete[] sanity;
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