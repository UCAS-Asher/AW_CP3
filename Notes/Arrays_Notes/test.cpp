// Asher Wangia
#include <iostream>
#include <limits>
using namespace std;

    int numbers[] = {8,6,2,9,1,11};

int main(){
    int length = size(numbers);
    for(int j = 0;j < length; j++){
        for(int i = 1;i < length; i++){
            if(numbers[i] < numbers[i-1]){
                int swap = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = swap;
            }
        }
    }
    
    for(int x = 0;x < length; x++){
        cout << numbers[x] << ", ";
    }

    return 0;
}