#include <iostream>

using namespace std;

void displayArray(int array[], int start, int end);
void mergeSort(int array[], int start, int end);
void merge(int array[], int start, int middle, int end);

int main()
{
    int n;

    cout << "Enter the number of elements in array: ";
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    mergeSort(array, 0, n - 1);

    cout << "After Sorting" << endl;
    displayArray(array, 0, n - 1);
}

void displayArray(int array[], int start, int end)
{
    for (int i = start; i <= end; i++)
        cout << array[i] << "\t";
}

void mergeSort(int array[], int start, int end)
{
    if (start >= end)
        return;

    int middle = (start + end) / 2;

    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);
    merge(array, start, middle, end);
}

void merge(int array[], int start, int middle, int end)
{
    int temp[100];

    int i = start;
    int j = middle + 1;
    int k = start;

    while (i <= middle && j <= end)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= middle)
        temp[k++] = array[i++];

    while (j <= end)
        temp[k++] = array[j++];

    for (int i = start; i <= end; i++)
        array[i] = temp[i];
}