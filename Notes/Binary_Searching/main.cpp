//AW Binary and Searching


//What is a potential issue with converting values to strings without control?
    //Data loss, unexpected formatting, performance overhead, and potential security vulnerabilities
//How can you control the way a value is converted to a string?
    //Use to_string, ostringstream or operator overloading
//Why is it useful to create a reusable function for converting values to strings?
    //it makes the code more readable and overall smaller
//What is parsing in the context of working with strings?
    //the process of analyzing a string of characters to extract meaningful information or to determine its structure according to a defined set of rules
//How do you extract specific information from a string in programming?
    //using the index, parsing, substr() or find()
//When a title contains a space, which function should you use to read it properly?
    // Use getline
//Why might extra zeros be added to a string when converting a value without control?
    //to_string includes a decimal point and a zero and Formatting with Padding can add zeros.
//How does controlling the string conversion process benefit your program?
    //Lets you control hoy your stuff are being saved in the string
//Give an example scenario where parsing a string would be necessary in a program.
    //Getting every word in a string that starts with a certain letter
//When writing to a binary file, what does the first parameter (reinterpret_cast<char*>(&numbers)) represent?
    //represents the starting address of the data you want to write, reinterpreted as a pointer to a sequence of bytes
//Why does the binary file only take 12 bytes while the array of integers might be larger?
    // A C++ array of integers in memory occupies space based on the number of elements and the size of each element
    //A binary file stores the raw byte representation of data
//What is the main difference between sequential search and binary search?
    // binary requires an ordered list to work
//In which type of data structure is binary search most efficient?
    //Lists that are properly ordered
//What is a key requirement for binary search to work correctly on a list?
    // The list needs to be ordered
//How does sequential search find an item in a list?
    //It goes through every item starting with the first and checks if its the item its looking for
//Why is binary search generally faster than sequential search for large, sorted lists?
    //it does less comparisons


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
    int year;
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

    auto movie = parseMovie("A New Hope,1977");
    fstream file;
    file.open("file.txt", ios::in | ios::out | ios::app);
    if(file.is_open()){




        file.close();
    }


    
    
    return 0;
}
