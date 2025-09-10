//AW, Pointers




//What is a pointer?
    //pointers hold addresses instead of information


//Why do we use pointers?
    //To get the location of a variable



//How do I create a pointer
    // do variable* pvariable = &variable



//What is indirection or de-referencing?
    // accessing data by its address instead of its value



//What are constant pointers? How are the different types used?
    //restrict either what the pointer can do with the data it points to or its own ability to change where it points



//How do you pass a pointer into a function?
    //You declare the function parameter as a pointer




//Why would you pass a pointer to a function?
    //To access large information


//How do you compare pointers?
    //You use comparison operators and it compares memory locations



//What is dynamic memory allocation?
    // assigning memory to a program during its execution



//What is the Stack?
    //An area of memory used for managing function calls, local variables and control flow. It is managed by the compiler for quick allocation of memory(Like a set of plates(organized))



//What is the Heap?
    //an area of memory used for dynamic memory. Stores data if the size is unknown at the time of compiling. Memory must be manually managed by the program. Used for flexible long-lived storage of complex data structures, objects, and large files.(Like a box full of stuff(not organized)(You have to delete stuff not used))



//What are smart pointers?
    // You dont have to delete pointers and can use them like variable
    // Unique Pointer - Owns that piece of memory and nothing else can use it
    // 




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

int capacity = 5;
int* sanity = new int[capacity];
int entries = 0;



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
    cout << (pnum > pday) << endl;
    if (pnum!= nullptr){
        cout << *pnum << endl;
        pnum++;
    }
    cout << *pnum << endl;


    while(true){
        cout << "Number: ";
        cin >> sanity[entries];
        if (cin.fail()) break;
        entries++;
        if(entries == capacity){
            capacity += 1;
            int* temp = new int[capacity];
            for(int i = 0; i < entries; i++)
                temp[i] = sanity[i];
            delete[] sanity;
            sanity = temp;
        }
    }

    for(int i = 0; i < entries; i++){
        cout << sanity[i] << endl;// Delete after done using or you get memory leak
         
    }
    delete[] sanity;
    return 0;










    return 0;
}