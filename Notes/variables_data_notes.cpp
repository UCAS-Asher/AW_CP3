// Asher Wangia, Variables, Data Types, Inputs and Outputs

//1. How are static and dynamically typed variables different?
    // A staticly typed variable needs to read your data type while dynamically typed variables arent read


//2. REMINDER: What is the difference between instantiating and declaring a variable?
    //declaring a variable lets you use it but it doesnt have a value and initializing gives it a value

//3. What case type should be used for c++ variables?
    //You should use snake_case


//4. What is the C++ standard library?
    // iostream which controls what goes in and out a program and stands for input output stream

//5. How do you access the standard library?
    //You use #include and the library you are accessing


//6. How do you create an output in C++?
    //Use cout << (What you want to print);
    // cout stand for console out 


//7. How do you create an input in C++?
    // Use cin >> (variable you want to use);
    // cin stands for console in


//8. What is the stream in C++?
    // Flow of information


//9. What is a constant?
    // A variable that cant be changed


//10. Why do we write constants?
    // write const in front of the variable data type

//Variable Types:
    // Short takes 2bytes of space and is -32,768 to 32,768 characters long
    // int takes 4bytes of space and is -2b to 2b characters long
    // long takes up the same space and is the same amount of characters long
    // long long takes up 8bytes of space and is big#5 characters long
    // floats take up 4bytes of space and is 3.4E38 characters long
    // doubles takes up 8 bytes of space and is 1.7E308 characters long 
    // long double takes up 8bytes of space and is 3.4E932 characters long
    // bool takes up 1 byte of space and is true/false
    // char is takes up 1 byte of space and is a single letter


//One needs to be decimal when dividing to get decimal


#include <iostream>
using namespace std;

int main(){
    int students = 11;
    double days = 5;
    long years = 2554l;// l at end or compiles to integer
    const float pi = 3.14f;// float will compile to double without f at the end
    bool on = true;
    char name = 'C';
    cout << "Tell me your age: ";
    int age;
    cin >> age;
    double divide = students/days;
    cout << divide;
    return 0;
}