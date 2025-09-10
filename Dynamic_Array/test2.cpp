
#include <iostream>
#include <memory>
using namespace std;

int capacity = 1;
int entries = 0;


int main(){

    unique_ptr <string> colors(new string[capacity]);
    *colors = new string[capacity];

    while(true){
        cout << "Number: ";
        cin >> colors[entries];
        if (cin.fail()) break;
            entries++;
        if(entries == capacity){
            capacity += 1;
            int* temp = new int[capacity];
            for(int i = 0; i < entries; i++)
                temp[i] = colors[i];
            colors = temp;
        }
    }
    

    for(int i = 0; i < entries; i++){
        cout << sanity[i] << endl;// Delete after done using or you get memory leak
         
    }
    delete[] sanity;
    
    

    return 0;

}