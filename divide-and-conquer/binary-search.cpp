#include <iostream>
#include <limits>

using namespace std;

int binarySearch(int array[], int start, int end, int search);

int main()
{
    int n;

    cout << "Enter the number of elements in array: ";
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements (in ascending order) " << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int search;
    cout << "Enter element to be searched: ";
    cin >> search;

    int index = binarySearch(array, 0, 10, search);

    if (index != -9999)
        cout << "Element found at position " << index << endl;
    else
        cout << "Element not found" << endl;
}

int binarySearch(int array[], int start, int end, int search)
{
    if (start > end)
        return -9999;

    int middle = (start + end) / 2;

    if (search == array[middle])
        return middle + 1;

    else
    {
        if (search > array[middle])
            return binarySearch(array, middle + 1, end, search);

        else
            return binarySearch(array, start, middle - 1, search);
    }
}