#include<iostream>

using namespace std;

typedef struct stack
{
   int data1;
   int data2;
   struct stack *link;
}stack;

int main(){
   int push(stack **, int , int );
   int pop(stack **, int *, int *);
   void quicksort(int[], int);
   int partition(int [], int *, int, int);
   stack *top;
   int i, lb, ub;  // lb indicates lower bound and ub indicates upper bound
   int a[50], n;
   cout << "Enter the total number of elements: " << endl;
   cin >> n;
   cout << "Enter array elements: " << endl;
   for(i=0; i<n; i++)
   {
      cin >> a[i];
   }
   quicksort(a, n);
   cout << "\n" << "After sorting: ";
   for(i=0; i<n; i++){
      cout << a[i] << " ";
   }
   cout << "\n";
   return 0;
}

int push(stack **top, int lb, int ub){
   stack *nn;
   nn = (struct stack*)malloc(sizeof(stack));
   (nn->data1) = lb;
   (nn->data2) = ub;
   if((*top) == NULL){
      (nn->link) = NULL;
      (*top) = nn;
   }else{
      (nn->link) = (*top);
      (*top) = nn;
   }
   return 0;
}

int pop(stack **top, int (*lb), int (*ub)){
   stack *ptr;
   if(*top == NULL){
      return 0;
   }
   ptr = (*top);
   (*lb) = ptr->data1;
   (*ub) = ptr->data2;
   (*top) = (*top)->link;
   free(ptr);
   return 0;
}

int partition(int a[50], int (*pi), int low, int high){ //pi holds the index of pivot
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

void quicksort(int a[50], int n){
   int lbound, ubound, pi;
   stack *top;
   top = NULL;
   push(&top, 0, n-1);
   while(top != NULL){
      pop(&top, &lbound, &ubound);

      partition(a, &pi, lbound, ubound);
      if(lbound < (pi-1)){
         push(&top, lbound, (pi-1));
      }
      if((pi+1) < ubound){
         push(&top, (pi+1), ubound);
      }
   }
}
