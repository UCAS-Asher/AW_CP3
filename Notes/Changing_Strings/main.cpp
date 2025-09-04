// Asher Wangia, Changing Strings



//How do I get a substring from within a string?
    // Use substr("Start Index", "End Index")


//How do I create an escape character in C++
    // The escape character is a \ 


//How do I convert a string to another data type?
    // Use sto"Initial of Data Type"()


//What is a raw string and when would I use it?
    // You would use a raw string to print characters you normally wouldnt be able to and it is when you do R"(The String You Want)"


#include <iostream>
#include <string>
using namespace std;


string name = "mango Mustard";
string sentence = "The quick brown fox jumps over the lazy dog!";

int main(){
    auto index = name.find(' ');
    string first_name =  name.substr(0,index);
    string last_name = name.substr(index+1);
    first_name[0] = toupper(first_name[0]);
    //tolower()


    cout << first_name << endl << last_name << endl;


    int length = size(sentence);
    for(int i = 0; i < length; i++){
        if(isspace(sentence[i])){
            sentence[i] = '_';
        }
        else if(isupper(sentence[i])){
            sentence[i] = tolower(sentence[i]);
        }
        else{
            sentence[i] = (char(int(sentence[i])+4 )% 26 + 97);
        }
    }

    cout << sentence << endl;

    cout << R"(This is a "Question" . . . I think🥭)";



    return 0;
}