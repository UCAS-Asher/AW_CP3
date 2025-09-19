//AW, Enumeration

//What is enumeration?
    //a data type that provides a way to assign names to a set of constants.

//How do you build enumeration?
    //you type enum then the name of the enum followed by the named constants enclosed in curly brackets

//How do we display our enumerator? 
    //You type the enumerator's name then :: in between then the constant's name

//Why does it matter that enumerators are constants??
    //Enumerators are not supposed to be changed

//What is the default beginning enumerator?
    // It starts from 0 and adds 1 from then on

//How do you give a different default value?
    //Change the value of the first number

//What is a strongly typed enumerator?
    //They are like normal enumerators but the type has to be declared

//How are strongly typed enumerators different from a normal one?
    //You have to assign a type while normal enumerators are always integers


#include <iostream>


using namespace std;

enum Menu{
    Find = 1,
    Battle,
    Heal 
};

enum Menu{
    List = 1,
    Add,
    Update 
};

enum class Operation{
    List = 1,
    Add ,
    Update
};


int main(){
    int input;



    cout <<
    "1: List Invoices" << endl <<
    "2: Add Invoices" << endl <<
    "3: Update Invoices" << endl <<
    "Select: ";
    cin >> input;

    if(input == Menu::Find){
        cout << "List invoices" << endl;
    }
    else if(input == Menu::Battle){
        cout << "I havent built this yet" << endl;
    }
    else if(input == Menu::Heal){
        cout << "Suprisingly I havent built this either" << endl;
    }
    else{
        cout << "Womp womp. Not an option." << endl;
    }



    return 0;
}