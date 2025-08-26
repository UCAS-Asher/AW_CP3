// AW, Strings, Arrays, conditionals

//What is Narrowing?
    // Move contents of a bigger variable into a variable with less space


//What is a basic way to generate random numbers in C++?



//What is an array?
    // A list in c++

//How do I create an array?
    // Type int variable_name[length] = {the data}

//How do you make strings in C?


//How did C++ improve creating strings? 
    // You dont have to specify your string length anymore


//How do I search a string?


//How do I modify a string?


//What are some string methods? 



#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    // low level version of random numbers
    int seconds = time(nullptr);
    srand(seconds);
    int my_num = rand() % 11;
    cout << my_num << endl;

    //Arrays need the index number listed in brackets when the variable is set
    int grades[11] = {99,24,48,67,48,84,77,85,68,98,78};
    cout << grades[3] << endl;

    //Strings
    string name = "67";
    cout << name << endl;
    string sentence = "Mustard Mangos 67";
    cout << sentence << endl;
    cout << sentence.length() << endl;
    cout << (name > sentence) << endl;
    // .starts_with() .ends_with() checks string's letters
    // .empty() checks if string is empty
    // .front() <= returns the first character
    // .back() <= returns the last character

    name.append(" 67");
    name.insert( 3, "67 ");
    //name.erase()
    //name.clear() <= makes empty string
    int first = sentence.find("67"); // <= beginning index of 1st occurance
    int end = first + 3;
    sentence.replace(first, end, "67 67");
    cout << name << endl;
    cout << sentence << endl;


    // Searching a string
    cout << sentence.find("BloxFruits") << endl;
    //rfind() <= starts the search at the end of the string
    // find_first_of() <= gets first occurance of any character in the given string 
    cout << name.find("7") << endl;
    cout << name.find_first_of("7") << endl;
    // find_last_of()
    cout << sentence.find_last_not_of("67") << endl;
    // .find_last_not_of()
    cout << sentence.substr(0,7) << endl;


    if(67 < 68){
        cout << "Mustard Mangos" << endl;
    }
    else if(67 > 66){
        cout  << "Mangos Mustard" << endl;
    }
    else{
        cout << "No Mustard or Mango" << endl;
    }


    return 0;
}