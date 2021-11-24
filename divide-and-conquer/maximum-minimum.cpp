#include <iostream>

using namespace std;

class MaxMin
{
public:
    int maximum;
    int minimum;
};

MaxMin maximumMinimum(int array[], int start, int end);

int main()
{
    int n;
    MaxMin maxMinPair;
    maxMinPair.minimum = 0;
    maxMinPair.maximum = 9;

    cout << "Enter the number of elements in array: ";
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    maxMinPair = maximumMinimum(array, 0, n - 1);
    cout << "Maximum: " << maxMinPair.maximum << endl;
    cout << "Minimum: " << maxMinPair.minimum << endl;
}

MaxMin maximumMinimum(int array[], int start, int end)
{

    MaxMin maxMin;

    if (start == end)
    {
        maxMin.maximum = array[start];
        maxMin.minimum = array[start];
    }
    else if (end - start == 1)
    {
        if (array[start] > array[end])
        {
            maxMin.maximum = array[start];
            maxMin.minimum = array[end];
        }
        else
        {

            maxMin.maximum = array[end];
            maxMin.minimum = array[start];
        }
    }
    else
    {
        int middle = (start + end) / 2;
        MaxMin maxMin1 = maximumMinimum(array, start, middle);
        MaxMin maxMin2 = maximumMinimum(array, middle + 1, end);

        if (maxMin1.maximum > maxMin2.maximum)
            maxMin.maximum = maxMin1.maximum;
        else
            maxMin.maximum = maxMin2.maximum;

        if (maxMin1.minimum < maxMin2.minimum)
            maxMin.minimum = maxMin1.minimum;
        else
            maxMin.minimum = maxMin2.minimum;
    }

    return maxMin;
}