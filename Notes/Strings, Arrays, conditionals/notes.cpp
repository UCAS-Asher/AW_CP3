// AW, Strings, Arrays, conditionals

//What is Narrowing?
    // Move contents of a bigger variable into a variable with less space


//What is a basic way to generate random numbers in C++?


//What is an array?


//How do I create an array?


//How do you make strings in C?


//How did C++ improve creating strings? 


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
    cout << my_num;


    return 0;
}