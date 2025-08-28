//Asher Wangia, User Login


#include <iostream>
using namespace std;

int admins_find(string admins[], string user_name){
    int admin = 0;
    
    for(int i = 0; i < 3; i++){
        if(user_name == admins[i]){
            admin +=1;
        }
    }
    
    
    return admin;    
}

int users_find(string users[], string user_name){
    int user = 0;
    
    for(int i = 0; i < 5; i++){
        if(user_name == users[i]){
            user +=1;
        }
    }
    
    
    return user;    
}

int main(){
    string admins[3] = {"Mango6", "Mustard7", "MangoMustard67"};
    string old_users[5] = {"MangoMustard", "MustardMango", "Mango", "Mustard", "Hello67"};
    int choice;
    cout << endl << "User Login" << endl << "1. Sign Up" << endl << "2. Login To Existing" << endl << "Choose a Number: ";
    cin >> choice;
    
    if (choice == 1){
        string new_name;
        cout << "What Username do you want to sign up as: ";
        cin >> new_name;
        cout << "Lets get you signed up " << new_name << endl;
        main();
    }
    else if (choice == 2){
        string user_name;
        cout << "Whats your Username: ";
        cin >> user_name;
        int admin = admins_find(admins, user_name);
        int user = users_find(old_users, user_name);

        if (admin > 0){
            cout << "Hello Admin " << user_name << endl;
        }
        else if (user > 0){
            cout << "Welcome Back " << user_name << endl;
        }
        else{
            cout << "User Does Not Exist" << endl;
        }
        main();
    }
    else{
        cout << "Program End";
    }
    return 0;
}
