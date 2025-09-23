//AW, Pokemon Battle

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

enum Main{
    Explore = 1,
    Battle,
    Inventory,
    Exit
};

enum Battle{
    Attack = 1,
    Items,
    Pokemon,
    Run

};

void print_one(string message){
    for(int i = 0; i < size(message); i++){
        cout << message[i];
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    cout << endl;
}

void explore(){

}


void battle(){

}

void items(){

}






int main(){
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    print_one("Welcome to the world of pokemon! This world is inhabited by creatures called pokemon! For some people, they are pets. Others use them for fights. What will you use them for as you explore this world?");
    print_one("Do you want to continue and explore this world(Y/N): ");
    string opening;

    if(!(cin >> opening)){
        cout << "" << endl << endl;
        cin.clear();
        cin.ignore();
        cout << "I will asume this is a Yes :)" << endl;
    }

    if(opening == "Y"){
        cout << "Nice Choice" << endl;
    }
    else if(opening == "N"){
        cout << "Bye Bye :(" << endl;
    }
    else{
        cout << "I will asume this is a Yes :)" << endl;
    }
   
    while(true){
        int choice;
        cout << "Main Menu" << endl << "1. Explore" << endl << "2. Battle" << endl << "3. Items" << endl << "4. Exit" << endl << "Choose a Number: ";

        while(!(cin >> choice)){
            cout << "Put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            cout << "Main Menu" << endl << "1. Explore" << endl << "2. Battle" << endl << "3. Items" << endl << "4. Exit" << endl << "Choose a Number: ";
        }

        if(choice == Main::Explore){
            explore();
        }
        else if(choice == Main::Battle){
            battle();
        }
        else if(choice == Main::Inventory){
            items();
        }
        else if(choice == Main::Exit){
            cout << "Program End";
            break;
        }
        else{
            cout << "Not an Option!";
        }
   }
}
