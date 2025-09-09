
#include <iostream>
using namespace std;


int capacity = 5;
int* sanity = new int[capacity];
int entries = 0;

int main(){
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
}