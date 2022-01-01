#include <iostream>

using namespace std;

void displayArray(int array[], int start, int end);

int main()
{
    int n;

    cout << "Enter the number of elements in array: ";
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    cout << "After Sorting" << endl;
    displayArray(array, 0, n - 1);
}

void displayArray(int array[], int start, int end)
{
    for (int i = start; i <= end; i++)
        cout << array[i] << "\t";
    cout << endl;
}