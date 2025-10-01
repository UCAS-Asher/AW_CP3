
#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;


struct Movie{
    int id;
    string title;
    int year;
};


int main(){
    ofstream file;
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
   cout << "Current working directory: " << filesystem::current_path() << std::endl;

    return 0;
}