#include <iostream>

using namespace std;

int main()
{
    void insert(double [4][4]);
    void display(double [4][4]);
    int n;
    // cout << "Enter the size of the array: ";
    //cin >> n;
    double a[4][4], b[4][4];

    cout << "\n Insert the values in the matrix a: \n";
    insert(a);

    cout << "\n Insert the values in the matrix b: \n";
    insert(b);

    cout << "\n a: \n";
    display(a);

    cout << "\n b: \n";
    display(b);

    return 0;
}

void insert(double x[4][4]){
    double n;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
        {
            cin >> n;
            x[i][j] = n;
        }
   }
}

void display(double x[4][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++) {
            cout << x[i][j] << "\t";
        }
        cout << "\n";
    }
}