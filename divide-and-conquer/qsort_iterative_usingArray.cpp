#include <iostream>
using namespace std;

#define MAX 50

int main(){
   int push(int [], int, int *);
   int pop(int [], int *, int *);
   int partition(int [], int *, int, int);
   int quicksort(int [], int);
   int a[50], n, i, x;
   cout << "Enter the total number of elements:" << "\n";
   cin >> n;
   cout << "Enter array elements:" << "\n";
   for(i=0; i<n; i++)
   {
      cin >> a[i];
   }
   quicksort(a, n);
   cout << "\n" << "After sorting: ";
   for(i=0; i<n; i++){
      cout << a[i] << " " ;
   }
   cout << "\n";
   return 0;
}

int push(int stack[MAX], int x, int (*top)){
    
    if((*top) == MAX-1){
        return 0;
    }else{
        (*top) = (*top) + 1;
        stack[*top] = x;
    }
    return 0;
}

int pop(int stack[MAX], int (*x), int (*top)){
    if((*top) == (-1)){
        return 0;
    }else{
        (*x) = stack[*top];
        (*top) = (*top) - 1;
    }
    return 0;
}

int partition(int a[50], int (*pi), int low, int high){
   int temp;
   int pivot = a[low];
   int down = low;
   int up = high;
   while(down < up){
      while(a[down] <= pivot){
         down = down + 1;
      }
      while(a[up] > pivot){
         up = up - 1;
      }
      if(down > up){
         break;
      }else{
         temp = a[down];
         a[down] = a[up];
         a[up] = temp;
      }
   }
   a[low] = a[up];
   a[up] = pivot;
   (*pi) = up;
   return 0;
}

int quicksort(int a[50], int n){
    int top , stack[MAX], l, b, pi;
    top = (-1);
    push(stack, 0, &top);
    push(stack, (n-1), &top);

    while(top >= 0){
        pop(stack, &b, &top);
        pop(stack, &l, &top);

        partition(a, &pi, l, b);

        if((pi-1) > l){
            push(stack, l, &top);
            push(stack, (pi-1), &top);
        }
        if((pi+1) < b){
            push(stack, (pi+1), &top);
            push(stack, b, &top);
        }
    }
}