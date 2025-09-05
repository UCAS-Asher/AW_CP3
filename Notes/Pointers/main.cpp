//Asher Wangia, Pointers




//What is a pointer?
    //pointers hold addresses instead of information


//Why do we use pointers?
    //To get the location of a variable



//How do I create a pointer
    // do variable* pvariable = &variable



//What is indirection or de-referencing?



//What are constant pointers? How are the different types used?



//How do you pass a pointer into a function?



//Why would you pass a pointer to a function?



//How do you compare pointers?



//What is dynamic memory allocation?



//What is the Stack?



//What is the Heap?



//What are smart pointers?




#include <iostream>


using namespace std;

int numbers[] = {4,2,6,8,14,24,65};

void divide(int* list, int size){
    for(int i = 0; i < size; i++){
        list[i] = list[i]/2;
        cout << list[i] << endl;
    }
    cout << "this is my numbers list " << list << endl;
}



int main(){
    int num = 4;
    int* pnum = &num;
    int day = 5;
    int month = 9;

    double pi = 3.141592;
    double gpa = 3.99999;

    *pnum = 8;

    // Constant Pointers
    const double* ppi = &pi;// Value at the location cant be changed
    ppi = &gpa;

    int* const pday= &day;// Can change value but not the location being pointed at
    *pday = 6;
    //*pday = &num;

    const int* const pmonth = &month;//Location and value cant be changed


    cout << "The number is " << num << endl;
    cout << "The location of num is " << pnum << endl; 
    divide(numbers, size(numbers));







    return 0;
}