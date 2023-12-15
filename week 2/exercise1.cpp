// CPP program to find minimum element in an array.
#include <iostream>
using namespace std;

int getMin(int arr[], int n)
{
	int res = arr[0];
	for (int i = 1; i < n; i++)
		res = min(res, arr[i]);
	return res;
}

int main()
{
	int arr[5];
	int arr_size = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < arr_size; i++){
        cout << "Enter an array value for position " << i + 1 << ": ";
        cin >> arr[i];
    }

	cout << "Minimum element of array: " << getMin(arr, arr_size) << endl;

	return 0;
}