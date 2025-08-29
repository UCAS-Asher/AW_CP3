//Asher Wangia, Arrays Notes

//How are for loops constructed in C++
//When do you need to use curly brackets in C++
    // When executing a specific piece of code based on a condition or maxing an array
//How do you compare items in arrays
    //Compare the items using their specific index and use ==
//How do you use an array as an argument in a function
    //run the function using the array and declare a paramater that is a list
//What is type_t
    //gives the max amount something can hold
//Why would we use type_t
    // to get the max amount something can hold
//How do you search an array
    //Check every index of the array using a loop
//How do you sort an array
    //You check every index in the array and swap items based on a condition multiple times
//How do you make a multi-dimensional array
    //add another index in the name of the variable when declaring: int list[2][2] = {{1,2},{3,4}}


#include <iostream>
#include <limits>


using namespace std;

string fam[6] = {"Mango", "Mustard", "Mangos", "Mustards", "MangoMustard", "MustardMango"};
string sibs[2] = {"MangoMustard", "MustardMango"};

int search(string list[], size_t len, string item){
    for(int i=0; i < len; i++){
        if (list[i] == item){
            cout << "You are a sibling\n";
            return 1;
        }
    }
    cout << "You are a parent!\n";
    return 0;
}

int main(){
    // cout << fam << endl;

    for(int i = 0;i < size(fam);i++){
        cout << fam[i] << "Asher\n";
        search(sibs, size(sibs), fam[i]);

    }


    // SIZE OF T
    cout << numeric_limits < long long > ::min() << endl;
    cout << numeric_limits < long long > ::max() << endl;
    cout << numeric_limits < size_t > ::min() << endl;
    cout << numeric_limits < size_t > ::max() << endl;



    //Structured Binding
    auto [q,w,e,r,t,y] = fam;
    cout << e << endl;


    //multi-dimensional array
    int matrix [3][3]= {{1,2,3},
            {4,5,6},
            {7,8,9}};

    return 0;
}
