//AW High score Leaderboard

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string string_input_val(string input, string prompt){
    while(!(cin >> input)){
            cout << "Not a Choice" << endl << endl;
            cin.clear();
            cin.ignore();
            cout << prompt;
    }
    return input;
}

int int_input_val(int input, string prompt){
    while(!(cin >> input)){
            cout << "Put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            cout << prompt;
    }
    return input;
}

void add_score(){

}

void see_score(){

}



int main(){
    int choice;
    cout << "High Score Choices\n 1. Add a Highscore\n 2. See High Scores\n 3. Exit\n Choose a Number: ";
    choice = int_input_val(choice, "High Score Choices\n 1. Add a Highscore\n 2. See High Scores\n 3. Exit\n Choose a Number: ");

    if(choice == 1){
        add_score();
    }
    else if(choice == 2){
        see_score();
    }
    else if(choice == 3){
        cout << "Bye Bye" << endl;
    }
    else{
        cout << "Not an Option" << endl;
        main();
    }
    return 0;
}