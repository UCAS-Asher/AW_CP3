//AW User Structure

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct User{
    string name;
    string pass;
    bool admin;
};


vector<User> users;


bool operator== (const User& user_compare, const User& user){
    return(user_compare.name == user.name && user_compare.pass == user.pass);
}


pair<bool, bool> check_user(string username, string password){
    User user_compare = {username, password, false};

    for(const auto& user: users){
        if(user_compare == user)
            return {true, user.admin};
    }
    return {false, false};
    
}

void login(){
    string username;
    string password;
    cout << "Login" << endl << "Username: ";
    cin >> username;
    cout << "Password(No Spaces): ";
    cin >> password;
    

    pair <bool, bool> result = check_user(username, password);
    bool is_user = result.first;
    bool admin = result.second;

    if(is_user){
        if(admin)
            cout << "Hello Admin " << username << endl << endl;
        else
            cout << "Hello " << username << endl << endl;
    }
    else{
        cout << "This User Does Not Exist" << endl << endl;
    }
}

void sign_up(){
    string username;
    string password;
    cout << "Sign Up" << endl << "Username: ";
    cin >> username;
    cout << "Password(No Spaces): ";
    cin >> password;

    pair <bool, bool> result = check_user(username, password);
    bool is_user = result.first;
    bool admin = result.second;


    if(is_user){
        cout << "This User Already Exists. Try Loging In" << endl << endl;
    }
    else{
        users.push_back({username, password, false});
        cout << "User Created!" << endl << "Hello " << username << endl << endl;
    }
}




int main(){
    users.push_back({"Max", "ILoveMangos", false});
    users.push_back({"Mathew", "ILoveMustard", false});
    users.push_back({"Mark", "ILove67", true});
    users.push_back({"Bob", "ILoveSteak", false});
    users.push_back({"Silas", "ILoveChicken", true});
    users.push_back({"Alex", "ILoveCereal", false});
    users.push_back({"Carter", "ILoveFries", true});
    users.push_back({"Dan", "ILoveBurgers", false});
    users.push_back({"Bart", "ILoveIceCream", false});
    users.push_back( {"Seth", "ILoveApples", false});


    int choice;
    cout << "Choices" << endl << "1. Start Program" << endl << "2. Exit" << endl << "Choose a Number: ";
    cin  >> choice;
    cout << endl;

    if(choice == 1){
        int choice2;
        cout << "Choices" << endl << "1. Login" << endl << "2. Sign Up" << endl << "Choose a Number: ";
        cin >> choice2;
        cout << endl;
        if(choice2 == 1){
            login();
        }
        else if(choice2 == 2){
            sign_up();
        }
        else{
            cout << "Not an Option" << endl;
        }
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