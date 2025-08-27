//Asher Wangia, User Login


#include <iostream>
using namespace std;

int main(){
    string admins[3] = {"Mango6", "Mustard7", "MangoMustard67"};
    string old_users[5] = {"MangoMustard", "MustardMango", "Mango", "Mustard", "Hello67"};
    int choice;
    cout << "User Login" << endl << "1. Sign Up" << endl << "2. Login To Existing" << endl << "Choose a Number: ";
    cin >> choice;
    
    if (choice == 1){
        string new_name;
        cout << "What Username do you want to sign up as: ";
        cin >> new_name;
        cout << endl << "Hello New User " << new_name;
        main();
    }
    else if (choice == 2){
        string user_name;
        cout << "Whats your Username: ";
        cin >> user_name;
        int admin = admins.find(user_name);
        int user = old_users.find(user_name);

    }
    else{
        cout << "Program End";
    }
    return 0;
}