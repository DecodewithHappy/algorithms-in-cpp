#include <iostream>
using namespace std;

#define MAX 50

int main(){
   int push(int [], int, int *);
   int pop(int [], int *, int *);
   int partition(int [], int *, int, int);
   int quicksort(int [], int);
   int a[50], n, i, item;  // a is the unordered array containing user given values, n is the number of elements, i is loop variable, item is the element to be pushed or popped from the stack
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

int push(int stack[MAX], int item, int (*top)){ 
    
    if((*top) == MAX-1){
        return 0;
    }else{
        (*top) = (*top) + 1;
        stack[*top] = item;
    }
    return 0;
}

int pop(int stack[MAX], int (*item), int (*top)){  
    if((*top) == (-1)){
        return 0;
    }else{
        (*item) = stack[*top];
        (*top) = (*top) - 1;
    }
    return 0;
}

int partition(int a[50], int (*pi), int low, int high){ // pi holds the index of pivot.  
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
    int top , stack[MAX], lbound, ubound, pi;
    top = (-1);
    push(stack, 0, &top);
    push(stack, (n-1), &top);

    while(top >= 0){
        pop(stack, &ubound, &top);
        pop(stack, &lbound, &top);

        partition(a, &pi, lbound, ubound);

        if((pi-1) > lbound){
            push(stack, lbound, &top);
            push(stack, (pi-1), &top);
        }
        if((pi+1) < ubound){
            push(stack, (pi+1), &top);
            push(stack, ubound, &top);
        }
    }
}