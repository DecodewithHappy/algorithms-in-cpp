#include <iostream>

using namespace std;

void displayArray(int array[], int start, int end);
void quickSort(int array[], int start, int end);
int partition(int array[], int start, int end);
void swap(int array[], int left, int right);

int main()
{
    int n;

    cout << "Enter the number of elements in array: ";
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    quickSort(array, 0, n);

    cout << "After Sorting" << endl;
    displayArray(array, 0, n - 1);
}

void displayArray(int array[], int start, int end)
{
    for (int i = start; i <= end; i++)
        cout << array[i] << "\t";

    puts("");
}

void quickSort(int array[], int start, int end)
{
    if (start >= end)
        return;

    int boundary = partition(array, start, end);
    quickSort(array, start, boundary);
    quickSort(array, boundary + 1, end);
}

int partition(int array[], int start, int end)
{
    int pivot = array[start];
    int left = start;
    int right = end;

    while (left < right)
    {
        do
        {
            left++;
        } while (array[left] <= pivot);

        do
        {
            right--;
        } while (array[right] > pivot);

        if (left < right)
            swap(array, left, right);
    }
    swap(array, start, right);

    return right;
}

void swap(int array[], int left, int right)
{
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}