#include <iostream>

using namespace std;

void displayArray(int array[], int start, int end);
void quickSort(int array[], int start, int end);
int partition(int array[], int start, int end);

int main()
{
    int n;

    cout << "Enter the number of elements in array: ";
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    quickSort(array, 0, n - 1);

    cout << "After Sorting" << endl;
    displayArray(array, 0, n - 1);
}

void displayArray(int array[], int start, int end)
{
    for (int i = start; i <= end; i++)
        cout << array[i] << "\t";
}

void quickSort(int array[], int start, int end)
{
    if (start >= end)
        return;

    int boundary = partition(array, start, end);
    quickSort(array, start, boundary);
    quickSort(array, boundary + 1, end);
}