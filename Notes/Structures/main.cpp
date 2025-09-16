//AW Structures


//What are structures?

//How do you build a structure?

//What can be held in a structure?
    //Properties

//How do you access the information in a structure?

//How do you overload an operator



#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date{
    short year = 1900;
    short month = 1;
    short day = 1;
};

struct Movie{
    string title;
    Date releaseDate;
    bool isPopular = true;

    bool ==(const Movie& movie){
        if(title == movie.title && releaseDate.year == movie.releaseDate.year && releaseDate.month == movie.releaseDate.month && releaseDate.day == movie.releaseDate.day && isPopular == movie.isPopular){
            return true;
        }
        else{
            return false;
        }
    }
};

struct Customer{
    string name;
    int id;
    string email;
};


int main(){
    vector<Movie> movies;
    
    //Movie movie = {"Terminator", 1984};
    movies.push_back({"Terminator", {1984, 6 ,1}});
    movies.push_back({"Terminator 2", 1987});
    

    Movie movie1 = {"Terminator", {1984, 6 ,1}};
    Movie movie2 = {"Terminator 2", 1987};

    //auto[title, releaseYear, isPopular]{movie};

    for(auto movie: movies){
        auto[title, releaseDate, isPopular]{movie};
        cout << "Movie Title: " << title << endl;
        cout << "Movie Year: " << releaseDate.year << endl;
        cout << "Movie Popular: " << isPopular << endl;
    }
    cout << movie1 == movie2 << endl;
   

    Customer cust;
    cust.name = "Greg";
    cust.id = 676767;
    cust.email = "greg@gmail.com";


    return 0;
}