// Asher Wangia, Tic Tac Toe

#include <iostream>
#include <string>
using namespace std;


void print_board(string board[3][3]){
    for(int y = 0; y < 3; y++){
        cout << endl;
        for(int x = 0; x < 3; x++){
            cout << board[y][x] << "  ";
        }
    }
    cout << endl;
}

string user_choice(){
    string user;
    cout << "Its Your Turn. Choose a Number: ";
    cin >> user;
    cout << endl;

    if(user == "1"|| user == "2"|| user == "3"|| user == "4"|| user == "5"|| user == "6"|| user == "7"|| user == "8"|| user == "9"){
        return user;
    }
    else{
        cout << "Not a Choice!" << endl;
        string user = user_choice();
        return user;
    }
}

int check_place(string place, string board[3][3]){   
    int place_good = 0;

    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(place == board[y][x]){
                place_good+=1;
            }
           
        }
    }
    return place_good;
}

string get_user_place(string board[3][3]){
    string place = user_choice();
    int place_good = check_place(place, board);
    if (place_good > 0){
        return place;
    }
    else{
        cout << "Spot Already Taken!";
        place = get_user_place(board);
        return place;

    }
}

void place_x(string place, string board[3][3]){
    if(place == "1"){
        board[0][0] = "X";
    }
    else if(place == "2"){
        board[0][1] = "X";
    }
    else if(place == "3"){
        board[0][2] = "X";
    }
    else if(place == "4"){
        board[1][0] = "X";
    }
    else if(place == "5"){
        board[1][1] = "X";
    }
    else if(place == "6"){
        board[1][2] = "X";
    }
    else if(place == "7"){
        board[2][0] = "X";
    }
    else if(place == "8"){
        board[2][1] = "X";
    }
    else if(place == "9"){
        board[2][2] = "X";
    }
}

void user_place(string board[3][3]){
    string place = get_user_place(board);
    place_x(place, board);
}

void game(){
    string board[3][3] = {{"1","2","3"}, {"4","X","6"}, {"7","8","9"}};
    cout << endl << "You are X" << endl;
    print_board(board);
    user_place(board);
    print_board(board);
}


int main(){
    int choice;
    cout << "Tic Tac Toe" << endl << "1. Play Game" << endl << "2. Exit Game" << endl << "Choose a Number: ";
    cin >> choice;

    if(choice == 1){
        
        game();
    }
    else if(choice == 2){
        cout << endl << "Program End";
    }
    else{
        cout << endl << "Not an Option!";
        main();
    }
    



    return 0;
}