//AW Movie Library

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Movie{
    string name;
    string director;
    int year;
    string genre;
    string rating;
};

enum Main{
    View = 1,
    Add,
    Delete,
    Search,
    Exit,
};

string str_input_val(string input, string prompt){
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

vector <Movie> update_library(){
    vector <Movie> movies;

    ifstream ifile;
    ifile.open("movies.csv");
    string line;
    
    getline(ifile, line);
    while(getline(ifile, line)){
        istringstream iss(line);
        string item;

        Movie movie;
        getline(iss, item, ',');
        movie.name = item;
        
        getline(iss, item, ',');
        movie.director = item;
        
        getline(iss, item, ',');
        movie.year = stoi(item);

        getline(iss, item, ',');
        movie.genre = item;

        getline(iss, item, ',');
        movie.rating = item;

        movies.push_back(movie);
    }
    
    ifile.close();
    return movies;
}


void view_movies(vector <Movie> movies){
    cout << "\nMovies\n";
    for(Movie movie: movies){
        cout << "Movie: " << movie.name << "\n";
        cout << "Director: " << movie.director << "\n";
        cout << "Release Year: " << movie.year << "\n";
        cout << "Genre: " << movie.genre << "\n";
        cout << "Rating: " << movie.rating << "\n";
        cout << "\n";
    }
}

Movie get_movie(){
    cout << "Movie Name: ";
    string movie_name;
    movie_name = str_input_val(movie_name, "Movie Name: ");

    cout << "Director: ";
    string director;
    director = str_input_val(director, "Director: ");

    cout << "Release Year: ";
    int year;
    year = int_input_val(year, "Release Year: ");

    cout << "Genre: ";
    string genre;
    genre = str_input_val(genre, "Genre: ");

    cout << "Rating: ";
    string rating;
    while(rating != "G" && rating != "PG" && rating != "PG-13" && rating != "R"){
        rating = str_input_val(rating, "Rating: ");
        if(rating != "G" && rating != "PG" && rating != "PG-13" && rating != "R"){
            cout << "Rating needs to be G, PG, PG-13 or R\n";
        }
    }
    
    Movie movie;
    movie.name = movie_name;
    movie.director = director;
    movie.year = year;
    movie.genre = genre;
    movie.rating = rating;

    return movie;
}

void add_movie(vector <Movie> movies){
    ofstream file("movies.csv");
    for(Movie movie: movies){
        file << movie.name << "," << movie.director << "," << movie.year << "," << movie.genre << "," << movie.rating << "\n";
    }
    Movie movie = get_movie();
    file << movie.name << "," << movie.director << "," << movie.year << "," << movie.genre << "," << movie.rating << "\n";
    file.close();
    cout << "Added Movie\n";
}

void delete_movie(vector <Movie> movies){
    bool deleted = false;
    cout << "What is the name of the movie you want to delete: ";
    string movie_name;
    str_input_val(movie_name, "What is the name of the movie you want to delete: ");
    for(Movie movie: movies){
        if(movie.name == movie_name){
            movies.(movie)
        }
    }
    if(deleted == false){
        cout << "Movie was not found!\n";
    }
    else if(deleted == true){
        cout << "Movie Deleted!\n";
    }
}

void search_movie(vector <Movie> movies){

}


int main(){
    while(true){
        vector <Movie> movies = update_library();
        int choice;
        cout << "Movie Library\n1. View Movies\n2. Add a Movie\n3. Delete a Movie\n4. Search Movies\nChoose a Number: ";
        choice = int_input_val(choice, "Movie Library\n1. View Movies\n2. Add a Movie\n3. Delete a Movie\n4. Search Movies\n5. Exit\nChoose a Number: ");

        if(choice == Main::View){
            view_movies(movies);
        }
        else if(choice == Main::Add){
            add_movie(movies);
        }
        else if(choice == Main::Delete){
            delete_movie(movies);
        }
        else if(choice == Main::Search){
            search_movie(movies);
        }
        else if(choice == Main::Exit){
            cout << "Have a Good Day\n";
            break;
        }
        else{
            cout << "Not an Option\n";
        }
    }
    return 0;
}