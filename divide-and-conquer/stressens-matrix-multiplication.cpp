#include <iostream>

using namespace std;

int main()
{
    void insert(double [4][4]);
    void display(double [4][4]);
    double call11(double [4][4]);
    double call12(double [4][4]);
    double call21(double [4][4]);
    double call22(double [4][4]);
    void display_matrix(double, double, double, double, double, double, double);

    //int n;
    // cout << "Enter the size of the array: ";
    //cin >> n;
    double a[4][4], b[4][4];
    double a11,a12,a21,a22,b11,b12,b21,b22,p,q,r,s,t,u,v,c11,c12,c21,c22;

    cout << "\n Insert the values in the matrix a: \n";
    insert(a);

    cout << "\n Insert the values in the matrix b: \n";
    insert(b);

    cout << "\n a: \n";
    display(a);

    cout << "\n b: \n";
    display(b);

    //divide the 4x4 matrix into four 2x2 matrix elements
    a11=call11(a);
    a12=call12(a);
    a21=call21(a);
    a22=call22(a);
    b11=call11(b);
    b12=call12(b);
    b21=call21(b);
    b22=call22(b);

    //apply the strassen's logic
    p=(a11+a22)*(b11+b22);
	q=(a21+a22)*b11;
	r=a11*(b12-b22);
	s=a22*(b21-b11);
	t=(a11+a12)*b22;
	u=(a11-a21)*(b11+b12);
	v=(a12-a22)*(b21+b22);

    //Display final matrix
    cout<<"\n final matrix";
    display_matrix(p,q,r,s,t,u,v);
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

double call11(double x[4][4]){
    return (x[1][1] * x[1][2]) + (x[1][2] + x[2][1]);
}

double call21(double x[4][4]){
    return (x[3][1] * x[4][2]) + (x[3][2] + x[4][1]);
}

double call12(double x[4][4]){
    return (x[1][3] * x[2][4]) + (x[1][4] * x[2][3]);
}

double call22(double x[4][4])
{
	return (x[2][3] * x[1][4])+ (x[2][4] * x[1][3]);
}

void display_matrix(double p, double q, double r, double s, double t, double u, double v){
    cout<<"\n"<<p+s-t+v<<" "<<r+t;
	cout<<"\n"<<q+s<<" "<<p+r-q+u;
}