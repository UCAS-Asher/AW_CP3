//AW Binary and Searching


//What is a potential issue with converting values to strings without control?

//How can you control the way a value is converted to a string?

//Why is it useful to create a reusable function for converting values to strings?

//What is parsing in the context of working with strings?

//How do you extract specific information from a string in programming?

//When a title contains a space, which function should you use to read it properly?

//Why might extra zeros be added to a string when converting a value without control?

//How does controlling the string conversion process benefit your program?

//Give an example scenario where parsing a string would be necessary in a program.

//Why are images, audio, and PDFs not readable by humans when stored in files?

//What file extensions are commonly used to create binary files?

//When writing to a binary file, what does the first parameter (reinterpret_cast<char*>(&numbers)) represent?

//Why does the binary file only take 12 bytes while the array of integers might be larger?

//How does reading individual numbers from a binary file differ from reading the entire list at once?

//What is the main difference between sequential search and binary search?

//In which type of data structure is binary search most efficient?

//What is a key requirement for binary search to work correctly on a list?

//How does sequential search find an item in a list?

//Why is binary search generally faster than sequential search for large, sorted lists?

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

/*
Convert other data types to strings!
istringstream =>
*/

using namespace std;

struct Movie{
    string title;
    int releaseDate;
    bool isPopular = true;

};

string to_string(double number, int precision){
    stringstream stream;
    stream << fixed << setprecision(number) << number;
    return stream.str();
}

Movie parseMovie(string str){
    stringstream stream;
    stream.str(str);

    Movie movie;
    getline(stream, movie.title, ',');
    stream >> movie.year;
    return movie;
}

int main(){
    double number = 3.14;
    cout << to_string(number, 2) << endl;

    //parsing
    string users = "10 20";
    stringstream fix;
    fix.str(users);
    int first;
    fix >> first;

    int second;
    fix >> second;

    cout << "first: " << first << endl << "second: " << second << endl;


    fstream file;
    file.open("file.txt", ios::in | ios::out | ios::app);
    if(file.is_open()){




        file.close();
    }


    
    
    return 0;
}
