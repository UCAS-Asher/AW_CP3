// Asher Wangia, Fahrenheit to Celsius

#include <iostream>
using namespace std;


int main(){
    cout << endl << endl << "Celcius To Farenheit Calculator" << endl << "1. Celcius to Fareneheit" << endl << "2. Farenheit to Celcius" << endl << "3. Exit" << endl << "Choose a Number : ";
    int choice;
    cin >> choice;
    cout << endl;

    if (choice == 1){
        double celcius;
        cout << "What tempreature in celcius do you want to convert: ";
        cin >> celcius;
        double farenheit = (celcius * 1.8) + 32;
        cout << celcius << " Celcius is " << farenheit << " Farenheit";
        main();
    }
    else if (choice == 2){
        double farenheit;
        cout << "What tempreature in farenheit do you want to convert: ";
        cin >> farenheit;
        double celcius = (farenheit - 32) * 5 / 9;
        cout << farenheit << " Farenheit is " << celcius << " Celcius";
        main();
    }
    else if (choice == 3){
        cout << "Program End";
    }
    else{
        cout << "Not an Option!" << endl;
        main();
    }
}