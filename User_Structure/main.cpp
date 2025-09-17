//AW User Structure

#include <iostream>
#include <string>
using namespace std;

struct User{
    string name;
    string password;
    bool admin;
};

User user1 = {"Max", "I Love Mangos", false};
User user2 = {"Mathew", "I Love Mustard", false};
User user3 = {"Mark", "I Love 67", true};
User user4 = {"Bob", "I Love Steak", false};
User user5 = {"Silas", "I Love Chicken", true};
User user6 = {"Alex", "I Love Cereal", false};
User user7 = {"Carter", "I Love Fries", true};
User user8 = {"", "I Love Mangos", false};


void login(){

}

void sign_up(){

}


int main(){
    int choice;
    cout << "Choices" << endl << "1. Start Program" << endl << "2. Exit" << endl << "Choose a Number: ";
    cin  >> choice;
    cout << endl;

    if(choice == 1){
        int choice2;
        cout << "Choices" << endl << "1. Login" << endl << "2. Sign Up" << endl << "Choose a Number: ";
        cin >> choice2;
        cout << endl;
        if(choice2 == 1)
            login();
        else if(choice2 == 2)
            sign_up();
        else
            cout << "Not an Option" << endl;
        main();
    }
    else if(choice == 2){
        cout << "Program End";
    }
    else{
        cout << "Not an Option" << endl;
        main();
    }


    return 0;
}