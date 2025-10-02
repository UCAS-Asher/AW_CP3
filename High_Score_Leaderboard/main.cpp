//AW High score Leaderboard

#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Score{
    string name;
    int score;
    string date;
};


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


vector <Score> update_scores(){
    vector <Score> scores;

    ifstream ifile;
    ifile.open("highscores.csv");
    string line;
    
    getline(ifile, line);
    while(getline(ifile, line)){
        istringstream iss(line);
        string item;

        Score score;
        getline(iss, item, ',');
        score.name = item;
        
        getline(iss, item, ',');
        score.score = stoi(item);
        
        getline(iss, item, ',');
        score.date = item;

        scores.push_back(score);
        
    }
    
    ifile.close();
    return scores;
}


void add_score(){

}

string get_date(){
    int month;
    cout << "Month: ";
    month = int_input_val(month, "Month: ");

    int day;
    cout << "Day: ";
    day = int_input_val(day, "Day: ");

    int year;
    cout << "Year: ";
    year = int_input_val(year, "Year: ");

}

void get_score(){
    string name;
    cout << "Name: ";
    name = string_input_val(name, "Name: ");

    int score;
    cout << "Score: ";
    score = int_input_val(score, "Score: ");

    string date;
    cout << "Month: ";
    date = string_input_val(date, "Date: ");
}

void see_score(const vector <Score>& scores){
    cout << "Leaderboard\n";
    for(Score score : scores){
        cout << "Name: " << score.name << "  Score: " << score.score << "  Date: " << score.date << endl;
    }
    cout << endl;
}



int main(){
    while(true){
        vector <Score> scores = update_scores();
        int choice;
        cout << "High Score Choices\n 1. Add a Highscore\n 2. See High Scores\n 3. Exit\n Choose a Number: ";
        choice = int_input_val(choice, "High Score Choices\n 1. Add a Highscore\n 2. See High Scores\n 3. Exit\n Choose a Number: ");

        if(choice == 1){
            get_score();
        }
        else if(choice == 2){
            see_score(scores);
        }
        else if(choice == 3){
            cout << "Bye Bye" << endl;
        }
        else{
            cout << "Not an Option" << endl;
            main();
        }
    }
    return 0;
}