// Asher Wangia, Tic Tac Toe

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
        string user_new = user_choice();
        return user_new;
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
        cout << "Spot Already Taken!" << endl;
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

string random_choice(){
    int seconds = time(nullptr);
    srand(seconds);
    int my_num = (rand() % 9) + 1;
    string ran_num = to_string(my_num);

    return ran_num;
}

string get_comp_place(string board[3][3]){
    string place = random_choice();
    int place_good = check_place(place, board);

    if (place_good > 0){
        return place;
    }
    else{
        place = get_comp_place(board);
        return place;

    }

}

void place_o(string place, string board[3][3]){
    if(place == "1"){
        board[0][0] = "O";
    }
    else if(place == "2"){
        board[0][1] = "O";
    }
    else if(place == "3"){
        board[0][2] = "O";
    }
    else if(place == "4"){
        board[1][0] = "O";
    }
    else if(place == "5"){
        board[1][1] = "O";
    }
    else if(place == "6"){
        board[1][2] = "O";
    }
    else if(place == "7"){
        board[2][0] = "O";
    }
    else if(place == "8"){
        board[2][1] = "O";
    }
    else if(place == "9"){
        board[2][2] = "O";
    }
}

void comp_place(string board[3][3]){
    string place = get_comp_place(board);
    place_o(place, board);
}

int check_win_x(string board[3][3]){
    int win = 0;
    if(board[0][0] == "X" && board[0][1] == "X" && board[0][2] == "X"){
        win+=1;
    }
    else if(board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X"){
        win+=1;
    }
    else if(board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X"){
        win+=1;
    }
    else if(board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X"){
        win+=1;
    }
    else if(board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X"){
        win+=1;
    }
    else if(board[0][2] == "X" && board[1][2] == "X" && board[2][2] == "X"){
        win+=1;
    }
    else if(board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X"){
        win+=1;
    }
    else if(board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X"){
        win+=1;
    }
    return win;
}

int check_win_o(string board[3][3]){
     int win = 0;
    if(board[0][0] == "O" && board[0][1] == "O" && board[0][2] == "O"){
        win+=1;
    }
    else if(board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O"){
        win+=1;
    }
    else if(board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O"){
        win+=1;
    }
    else if(board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O"){
        win+=1;
    }
    else if(board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O"){
        win+=1;
    }
    else if(board[0][2] == "O" && board[1][2] == "O" && board[2][2] == "O"){
        win+=1;
    }
    else if(board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O"){
        win+=1;
    }
    else if(board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O"){
        win+=1;
    }
    return win;
}

int check_full(string board[3][3]){
    if(board[0][0] != "1" && board[0][1] != "2" && board[0][2] != "3" && board[1][0] != "4" && board[1][1] != "5" && board[1][2] != "6" && board[2][0] != "7" && board[2][1] != "8" && board[2][2] != "9"){
        return 1;
    }
    return 0;
}

int turns(string board[3][3]){
    user_place(board);
    print_board(board);
    
    int win_x = check_win_x(board);
    if(win_x > 0){
        cout << "You Won!" << endl;
        return 1;
    }
    else if(check_full(board) > 0){
        cout << "Tie!" << endl;
        return 1;
    }

    comp_place(board);
    print_board(board);

    int win_o = check_win_o(board);
    if(win_o > 0){
        cout << "The Computer Won!" << endl;
        return 1;
    }
    else if(check_full(board) > 0){
        cout << "Tie!" << endl;
        return 1;
    }

    return 0;
}

void game(){
    string board[3][3] = {{"1","2","3"}, {"4","5","6"}, {"7","8","9"}};
    cout << endl << "You are X" << endl;
    print_board(board);
    int game_win = 0;
    while(game_win != 1){
        int game_win = turns(board);
    }
    cout << "Game Over" << endl;
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