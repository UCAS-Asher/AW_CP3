//Asher Wangia, Arrays Notes

//How are for loops constructed in C++
//When do you need to use curly brackets in C++
//How do you compare items in arrays
//How do you use an array as an argument in a function
//What is type_t
//Why would we use type_t
//How do you search an array
//How do you sort an array
//How do you make a multi-dimensional array


#include <iostream>

using namespace std;

string fam[6] = {"Mango", "Mustard", "Mangos", "Mustards", "MangoMustard", "MustardMango"};
string sibs[2] = {"MangoMustard", "MustardMango"};

void search(string list, string item){
    cout  << list << endl;
}

int main(){
    for(int i = 0;i < size(fam);i++){
        cout << fam[i] << "Asher\n";
        if(fam[i] == sibs[i-4])
            cout << "They are a sibling!\n";

    }


    return 0;
}