// AW Dynamic Array


#include <iostream>
#include <memory> // Required for std::unique_ptr
#include <algorithm> // Required for std::copy
using namespace std;

bool check_if_digit(const string& str){
    for (char i : str) {
        if (isdigit(i)) {
            return true;
        }
    }
    return false;
}


void program(){
    int space = 5;
    unique_ptr<string[]> colors = make_unique<string[]>(space);
    int entries = 0;

    while(true){
        cout << "Number: ";
        cin >> colors[entries];
        if(check_if_digit(colors[entries]) == true){
            break;
        }
        entries++;

        if(entries == space){
            space += 1;
            unique_ptr<string[]> temp = make_unique<string[]>(space);
            copy(colors.get(), colors.get() + entries, temp.get());
            colors = move(temp);
        }
    }

    for (int i = 0; i < entries; i++){
        cout << colors[i] << endl;
    }
    cout << endl;

}


int main(){
    int choice;
    cout << "Choices" << endl << "1. Start Program" << endl << "2. Exit" << endl << "Choose a Number: ";
    cin  >> choice;
    cout << endl;

    if(choice == 1){
        cout << "List as many colors as you can. Type a number when you are done" << endl;
        program();
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
