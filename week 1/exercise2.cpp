#include <iostream>
using namespace std;

int main(){
    int array[5];
    int size = sizeof(array)/sizeof(array[0]);
    float sum = 0;
    float max = 0;
    

    for(int i = 0; i < size; i++){
        cout << "Enter an array value for position " << i + 1 << ": ";
        cin >> array[i];
        sum += array[i];
        if(max < array[i]){
            max = array[i];
        }
    }

    cout << "The average of the array elements is: " << sum/size << endl;
    cout << "The maximum value of the array is: " << max << endl;

    return 0;
}
