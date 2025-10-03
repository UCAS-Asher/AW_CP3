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


void add_score(string name, int score, string date, const vector <Score>& scores){
    ofstream file("highscores.csv");
    bool in_file = false;

    if (file.is_open()) {
        file << "Name,Score,Date\n";

        for (const Score& comp_score : scores) {
            if (!in_file && score > comp_score.score) {
                file << name << "," << score << "," << date << "\n";
                in_file = true;
            }
            file << comp_score.name << "," << comp_score.score << "," << comp_score.date << "\n";
        }

        
        if (!in_file) {
            file << name << "," << score << "," << date << "\n";
        }
        
        cout << "Added Score!\n";
        file.close();
    }
    else{
        cout << "File does not exist!\n";
    }
}

string get_date(){
    int month;
    while(month > 12 || month < 1){
        cout << "Month: ";
        month = int_input_val(month, "Month: ");
        if(month > 12 || month < 1){
            cout << "Put an actual Month!\n";
        }
    }
    
    
    int day;
    while(day > 31 || day < 1){
        cout << "Day: ";
        day = int_input_val(day, "Day: ");
        if(day > 31 || day < 1){
            cout << "Put an actual day!\n";
        }
    }

    int year;
    cout << "Year: ";
    year = int_input_val(year, "Year: ");


    string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

    return date;
}

void get_score(const vector <Score>& scores){
    string name;
    cout << "Name: ";
    name = string_input_val(name, "Name: ");

    int score;
    cout << "Score: ";
    score = int_input_val(score, "Score: ");

    string date = get_date();
    add_score(name, score, date, scores);
    
}

void see_score(const vector <Score>& scores){
    cout << "Leaderboard\n";
    for(Score score : scores){
        cout << "Name: " << score.name << "  Score: " << score.score << "  Date: " << score.date << endl;
    }
    cout << endl;
}

void save_scores(vector <Score> scores){
    ofstream file("highscores.csv");

    if (file.is_open()) {
        file << "Name,Score,Date\n";

        for (const Score& comp_score : scores) {
            file << comp_score.name << "," << comp_score.score << "," << comp_score.date << "\n";
        }
        
        cout << "Saved Scores!\n";
        file.close();
    }
    else{
        cout << "File does not exist!\n";
    }
}


int main(){
    while(true){
        vector <Score> scores = update_scores();
        int choice;
        cout << "High Score Choices\n 1. Add a Highscore\n 2. See High Scores\n 3. Exit\n Choose a Number: ";
        choice = int_input_val(choice, "High Score Choices\n 1. Add a Highscore\n 2. See High Scores\n 3. Exit\n Choose a Number: ");

        if(choice == 1){
            get_score(scores);
        }
        else if(choice == 2){
            see_score(scores);
        }
        else if(choice == 3){
            cout << "Bye Bye" << endl;
            save_scores(scores);
            break;
        }
        else{
            cout << "Not an Option" << endl;
        }
    }
    return 0;
}