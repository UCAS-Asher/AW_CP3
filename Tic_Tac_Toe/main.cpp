// Asher Wangia, Tic Tac Toe

#include <iostream>
#include <string>
using namespace std;


void print_board(int board[3][3]){
    for(int y = 0; y < 3; y++){
        cout << endl;
        for(int x = 0; x < 3; x++){
            cout << board[y][x] << "  ";
        }
    }
    cout << endl;
}

int user_choice(){
    int user;
    cout << "Its Your Turn. Choose a Number: ";
    cin >> user;
    cout << endl;

    if(user == 1|| user == 2|| user == 3|| user == 4|| user == 5|| user == 6|| user == 7|| user == 8|| user == 9){
        return user;
    }
    else{
        cout << "Not a Choice!" << endl;
        user_choice();
    }
}

int place_check(int place, int board[3][3]){
    int options[9];
    
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(to_string(board[y][x]) != "X" && to_string(board[y][x]) != "O"){
                options.add()
            }
        }
    }

}

void user_place(){}

void game(){
    int board[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout << endl << "You are X" << endl;
    print_board(board);
    user_place();
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