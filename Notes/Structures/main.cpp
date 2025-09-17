//AW Structures


//What are structures?
    //a user-defined data type that groups together variables of different data types under a single name

//How do you build a structure?
    //use the struct keyword provide a name for your structure declare its variables of different types

//What can be held in a structure?
    //Properties

//How do you access the information in a structure?
    //a dot between the structure  name and the variable you want to access

//How do you overload an operator?
    //you define an operator function using the operator keyword followed by an operator symbol



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

};

struct Customer{
    string name;
    int id;
    string email;
};


bool operator== (const Movie& first, const Movie& second){
    return(first.title == second.title && 
        first.releaseDate.year == second.releaseDate.year && 
        first.releaseDate.month == second.releaseDate.month && 
        first.releaseDate.day == second.releaseDate.day && 
        first.isPopular == second.isPopular);
}
    

ostream& operator<<(ostream& stream, Movie& movie){
    stream << movie.title;
    return stream;
}

ostream& operator<<(ostream& stream, Customer& customer){
    stream << customer.name;
    return stream;
}


void showMovie(Movie* movie){
    cout << movie ->title << endl;
}


int main(){
    vector<Movie> movies;
    
    //Movie movie = {"Terminator", 1984};
    movies.push_back({"Terminator", {1984, 6 ,1}});
    movies.push_back({"Terminator 2", 1987});
    

    Movie movie1 = {"Terminator", {1984, 6 ,1}};
    Movie movie2 = {"Terminator 2", 1987};
    showMovie(&movie1);


    //auto[title, releaseYear, isPopular]{movie};

    for(auto movie: movies){
        auto[title, releaseDate, isPopular]{movie};
        cout << "Movie Title: " << title << endl;
        cout << "Movie Year: " << releaseDate.year << endl;
        cout << "Movie Popular: " << isPopular << endl;
    }
    if(movie1 == movie2){
        cout << movie1 << "Equal" << endl;
    }
    else{
        cout << movie1 << " is not " << movie2 << endl;
    }
   

    Customer customer;
    customer.name = "Greg";
    customer.id = 676767;
    customer.email = "greg@gmail.com";


    return 0;
}