// AW Text Files

#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//What are the 3 main sources of data for a program
    // terminal, file, network

//What are streams?


//What are the different streams we might need to include in a program? 
    //istream, ostream

//What is the base class for all streams?
    //ios

//What is buffer?
    //A temporary storage in memory for reading values

//How do you clear the buffer?
    //Use cin.ignore("Amount Characters to ignore, when to stop ignoring")


//How do you handle invalid inputs from the terminal
    //Use .fail() detects user instead of a number


//What streams are for files specifically


//How do you write to a text file?


//What do stream manipulators let us do?


//How do you write to a CSV?
    //You open the csv and do file << 



//How do you read a text file?


//How do you read a CSV file?


//What is a delimiter?
    // character used to seperate data in csv

//How do you read an entire CSV?

//How do you turn items from a CSV into objects of a structure?

struct Movie{
    int id;
    string title;
    int year;
};


int get_number(const string& prompt){
    int num;

    while(true){
        cout << prompt;
        cin >> num;
        if(cin.fail()){
            cout << "Enter a valid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    return num;
}

int main(){

    /*
    terminal - cout, cin (User given)
    file - txt, csv, binary
    network - internet, other computers
    */

    int first = get_number("First: ");
    int second = get_number("Second: ");
    cout << "You entered " << first << " and " << second << endl;

    /*
    ifstream > input files stream
    ofstream < Output file stream
    fstream <> combines functionality
    */
   ofstream file;
   file.open("Notes/Text_Files/data.txt");
   if(file.is_open()){
    file << setw(20) << "Hello " << setw(20) << "World";
    file.close();
   }


   file.open("data.csv");
   if(file.is_open()){
    file << "id,title,year\n"
    << "1,Terminator 1,1984\n"
    << "2,Terminator 2,1981\n";
    file.close();
   }



   ifstream ifile;
   ifile.open("data.csv");
   string line;
   vector <Movie> movies;
   if(ifile.is_open()){
    getline(ifile, line);
    while(getline(ifile, line)){
        istringstream iss(line);
        string item;

        Movie movie;
        getline(iss, item, ',');
        movie.id = stoi(item);
        getline(iss, item, ',');
        movie.title = item;
        getline(iss, item, ',');
        movie.year = stoi(item);

        movies.push_back(movie);
      
    }
    ifile.close();
    for(Movie i: movies){
        cout << i.title << endl;
    }
   }








    return 0;
}