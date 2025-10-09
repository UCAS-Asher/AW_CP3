//AW Movie Library

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

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

string input_val_space(string input, string prompt){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(!(getline(cin, input))){
            cout << "Not a Choice\n\n";
            cin.clear();
            cin.ignore();
            cout << prompt;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

string str_input_val(string input, string prompt){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(!(cin >> input)){
            cout << "Not a Choice\n\n";
            cin.clear();
            cin.ignore();
            cout << prompt;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

int int_input_val(int input, string prompt){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(!(cin >> input)){
            cout << "Put a Number!\n\n";
            cin.clear();
            cin.ignore();
            cout << prompt;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

vector <Movie> update_library(){
    vector <Movie> movies;

    ifstream ifile;
    ifile.open("Movie_Library/movies.csv");
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

void add_movie(const vector <Movie>& movies){
    ofstream file("Movie_Library/movies.csv");
    for(Movie movie: movies){
        file << movie.name << "," << movie.director << "," << movie.year << "," << movie.genre << "," << movie.rating << "\n";
    }
    Movie movie = get_movie();
    file << movie.name << "," << movie.director << "," << movie.year << "," << movie.genre << "," << movie.rating << "\n";
    file.close();
    cout << "Added Movie\n";
}

void delete_movie(){
    bool deleted = false;
    cout << "What is the name of the movie you want to delete: ";
    string movie_name;
    movie_name = str_input_val(movie_name, "What is the name of the movie you want to delete: ");
    
    fstream ifile;
    ifile.open("Movie_Library/movies.csv");
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

        if(movie.name == movie_name){
            deleted = true;
        }
        else{
            ifile << movie.name << "," << movie.director << "," << movie.year << "," << movie.genre << "," << movie.rating << "\n";
        }

    }
    ifile.close();


    if(deleted == false){
        cout << "Movie was not found!\n";
    }
    else if(deleted == true){
        cout << "Movie Deleted!\n";
    }
}

bool search_name(bool found, const vector <Movie>& movies){
    cout << "What is the name of the movie you want to find: ";
    string movie_name;
    movie_name = input_val_space(movie_name, "What is the name of the movie you want to find: ");
    
    cout << "\nMovies\n";
    for(Movie movie: movies){
        if(movie.name.find(movie_name) != string::npos){
            found = true;
            cout << "Movie: " << movie.name << "\n";
            cout << "Director: " << movie.director << "\n";
            cout << "Release Year: " << movie.year << "\n";
            cout << "Genre: " << movie.genre << "\n";
            cout << "Rating: " << movie.rating << "\n";
            cout << "\n";
        }
    }
    return found;
}

bool search_director(bool found,const vector <Movie>& movies){
    cout << "What is the director of the movie you want to find: ";
    string movie_director;
    movie_director = input_val_space(movie_director, "What is the director of the movie you want to find: ");
    
    cout << "\nMovies\n";
    for(Movie movie: movies){
        if(movie.director.find(movie_director) != string::npos){
            found = true;
            cout << "Movie: " << movie.name << "\n";
            cout << "Director: " << movie.director << "\n";
            cout << "Release Year: " << movie.year << "\n";
            cout << "Genre: " << movie.genre << "\n";
            cout << "Rating: " << movie.rating << "\n";
            cout << "\n";
        }
    }
    return found;
}

bool search_year(bool found,const vector <Movie>& movies){
    cout << "What is the release year of the movie you want to find: ";
    int movie_year;
    movie_year = int_input_val(movie_year, "What is the release year of the movie you want to find: ");
    
    cout << "\nMovies\n";
    for(Movie movie: movies){
        if(movie.year == movie_year){
            found = true;
            cout << "Movie: " << movie.name << "\n";
            cout << "Director: " << movie.director << "\n";
            cout << "Release Year: " << movie.year << "\n";
            cout << "Genre: " << movie.genre << "\n";
            cout << "Rating: " << movie.rating << "\n";
            cout << "\n";
        }
    }
    return found;
}

bool search_genre(bool found,const vector <Movie>& movies){
cout << "What is the genre of the movie you want to find: ";
    string movie_genre;
    movie_genre = str_input_val(movie_genre, "What is the genre of the movie you want to find: ");
    
    cout << "\nMovies\n";
    for(Movie movie: movies){
        if(movie.genre == movie_genre){
            found = true;
            cout << "Movie: " << movie.name << "\n";
            cout << "Director: " << movie.director << "\n";
            cout << "Release Year: " << movie.year << "\n";
            cout << "Genre: " << movie.genre << "\n";
            cout << "Rating: " << movie.rating << "\n";
            cout << "\n";
        }
    }
    return found;
}

bool search_rating(bool found,const vector <Movie>& movies){
    cout << "What is the rating of the movie you want to find: ";
    string movie_rating;
    movie_rating = str_input_val(movie_rating, "What is the rating of the movie you want to find: ");
    
    cout << "\nMovies\n";
    for(Movie movie: movies){
        if(movie.rating == movie_rating){
            found = true;
            cout << "Movie: " << movie.name << "\n";
            cout << "Director: " << movie.director << "\n";
            cout << "Release Year: " << movie.year << "\n";
            cout << "Genre: " << movie.genre << "\n";
            cout << "Rating: " << movie.rating << "\n";
            cout << "\n";
        }
    }
    return found;
}

void search_movie(const vector <Movie>& movies){
    bool found = false;
    int choice;
    cout << "Search By\n1. Movie Name\n2. Director\n3. Release year\n4. Genre\n5. Rating\nChoose Number: ";
    choice = int_input_val(choice, "Search By\n1. Movie Name\n2. Director\n3. Release year\n4. Genre\n5. Rating\nChoose Number: ");

    if(choice == 1){
        found = search_name(found, movies);
    }
    else if(choice == 2){
        found = search_director(found, movies);
    }
    else if(choice == 3){
        found = search_year(found, movies);
    }
    else if(choice == 4){
        found = search_genre(found, movies);
    }
    else if(choice == 5){
        found = search_rating(found, movies);
    }
    else{
        cout << "Not an Option\n";
        search_movie(movies);
        found = true;
    }

    if(found == false){
        cout << "Movie Not Found\n";
    }
}


int main(){
    while(true){
        vector <Movie> movies = update_library();
        int choice;
        cout << "Movie Library\n1. View Movies\n2. Add a Movie\n3. Delete a Movie\n4. Search Movies\n5. Exit\nChoose a Number: ";
        choice = int_input_val(choice, "Movie Library\n1. View Movies\n2. Add a Movie\n3. Delete a Movie\n4. Search Movies\n5. Exit\nChoose a Number: ");

        if(choice == Main::View){
            view_movies(movies);
        }
        else if(choice == Main::Add){
            add_movie(movies);
        }
        else if(choice == Main::Delete){
            delete_movie();
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