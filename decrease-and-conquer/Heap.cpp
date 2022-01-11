#include <iostream>
using namespace std;

#define MAX 100

int main(){
    int insert(int [MAX], int *, int);
    void display(int [MAX], int);
    void BuildHeap(int [MAX], int);
    void HeapSort(int [MAX], int);

    int ch, arr[MAX], n, value, result;
    n = 0;
    while(1){
        cout << "\n\t\tMENU\t\t\t\n";
        cout << "1.Insert Elements\t2.Display Elements\n";
        cout << "3.Build Heap\t\t4.Heap Sort\n";
        cout << "5.Exit\n\n";
        cout << "Enter any value from the menu : ";
        cin >> ch;

        switch(ch){
            case 1:
                 cout << "\nEnter the value : ";
                 cin >> value;
                 result = insert(arr, &n, value);
                 if(result == -1){
                     cout << "\nArray is Full!!\n";
                 }else{
                     cout << "\nInsertion Successful\n";
                 }
                 break;
            case 2:
                 display(arr, n);
                 break;
            case 3:
                 BuildHeap(arr, n);
                 break;
            case 4:
                 cout << "\nResult after sorting\n";
                 HeapSort(arr, n);
                 break;
            case 5:
                 return 0;
                 break;
            default:
                 cout << "\nInvalid Choice!!!\n";
                 break;
        }
    }
}

//insert func to enter elements inside the array
int insert(int arr[MAX], int (*n), int value){
    if((*n) == MAX){
        return -1;
    }
    arr[(*n)] = value;
    (*n) = (*n) + 1;
    return 1;
}

//display func to display the array elements
void display(int arr[MAX], int n){
    int i;
    if(n == 0){
        cout << "\nArray is empty!!\n";
        return;
    }
    for(i=0; i<n; i++){
       cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int (*value1), int (*value2)){
    int t;
    t = (*value1);
    (*value1) = (*value2);
    (*value2) = t;
}

//to maintain the max-heap property in a tree where both sub-trees are max-heaps, we need to run heapify on the root element repeatedly until it is larger than its children or it becomes a leaf node.

void heapify(int arr[MAX], int n, int i){
    void swap(int *, int *);
    int largest = i;
    int left = (2*i+1);
    int right = (2*i+2);

    if((left < n) && (arr[left] > arr[largest])){
        largest = left;
    }

    if((right < n) && (arr[right] > arr[largest])){
        largest = right;
    }

    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

//We will apply this buildheap func to the non-leaf nodes as leaf nodes are already considered heap
//This is a bottom-up process
void BuildHeap(int arr[MAX], int n){
    void heapify(int [MAX], int, int);
    int i;
    for(i=n/2; i>=0; i--){
        heapify(arr, n, i);
    }
}

void HeapSort(int arr[MAX], int n){
    int i;
    BuildHeap(arr, n);
    for(i=(n-1); i>=0; i--){
        swap(arr[0], arr[i]);// swapping of last-element and the root node will take place initially
        heapify(arr, i, 0);
    }
}

//let the initial array be arr = [1,12,9,5,6,10]
//after heapify arr = [12,6,10,5,1,9]
//after heapsort arr = [1,5,6,9,10,12]