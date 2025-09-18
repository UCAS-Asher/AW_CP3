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


bool check_login(string username, string password){
    User user_compare = {username, password};

    for(auto user: users){
        if(user_compare == user)
            return true, user.admin;
        else
            return false, false;
    }
}

void login(){
    string username;
    string password;
    cout << "Login" << endl << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << endl;


    bool is_user, admin = check_login(username, password);

    if(is_user == true){
        if(admin == true)
            cout << "Hello Admin " << username << endl;
        else
            cout << "Hello " << username << endl;
    }
    else{
        cout << "This User Does Not Exist" << endl;
    }
}

void sign_up(){

}


int main(){
    users.push_back({"Max", "I Love Mangos", false});
    users.push_back({"Mathew", "I Love Mustard", false});
    users.push_back({"Mark", "I Love 67", true});
    users.push_back({"Bob", "I Love Steak", false});
    users.push_back({"Silas", "I Love Chicken", true});
    users.push_back({"Alex", "I Love Cereal", false});
    users.push_back({"Carter", "I Love Fries", true});
    users.push_back({"Dan", "I Love Burgers", false});
    users.push_back({"Bart", "I Love Ice Cream", false});
    users.push_back( {"Seth", "I Love Apples", false});














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
            string username;
            string password;
            cout << "Login" << endl << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << endl;


            bool is_user, admin = check_login(username, password);

            if(is_user == true){
                if(admin == true)
                    cout << "Hello Admin " << username << endl;
                else
                    cout << "Hello " << username << endl;
            }
            else{
                cout << "This User Does Not Exist" << endl;
            }
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