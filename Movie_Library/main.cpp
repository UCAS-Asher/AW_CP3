//AW Movie Library

#include <iostream>
#include <vector>

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

void view_movies(){

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

void add_movie(){
    Movie movie = get_movie();

    
    file.open("movies.csv");
}

void delete_movie(){

}

void search_movie(){

}


int main(){
    vector <Movie> movies;

    while(true){
        int choice;
        cout << "Movie Library\n1. View Movies\n2. Add a Movie\n3. Delete a Movie\n4. Search Movies\nChoose a Number: ";
        choice = int_input_val(choice, "Movie Library\n1. View Movies\n2. Add a Movie\n3. Delete a Movie\n4. Search Movies\n5. Exit\nChoose a Number: ");

        if(choice == Main::View){
            view_movies();
        }
        else if(choice == Main::Add){
            add_movie();
        }
        else if(choice == Main::Delete){
            delete_movie();
        }
        else if(choice == Main::Search){
            search_movie();
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