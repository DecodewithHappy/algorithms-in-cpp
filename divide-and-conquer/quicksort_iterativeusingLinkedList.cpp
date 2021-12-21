#include<iostream>

using namespace std;

typedef struct stack
{
   int d1;
   int d2;
   struct stack *link;
}stack;

int main(){
   int push(stack **, int , int );
   int pop(stack **, int *, int *);
   void quicksort(int[], int);
   int partition(int [], int *, int, int);
   stack *top;
   int i, lb, ub;
   int a[50], n;
   cout << "Enter the total number of elements: " << endl;
   cin >> n;
   cout << "Enter array elements: " << endl;
   for(i=0; i<n; i++)
   {
      cin >> a[i];
   }
   quicksort(a, n);
   cout << "\n" << "After sorting";
   for(i=0; i<n; i++){
      cout << a[i] << " ";
   }
   cout << "\n";
   return 0;
}

int push(stack **top, int lb, int ub){
   stack *nn;
   nn = (struct stack*)malloc(sizeof(stack));
   (nn->d1) = lb;
   (nn->d2) = ub;
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
   (*lb) = ptr->d1;
   (*ub) = ptr->d2;
   (*top) = (*top)->link;
   free(ptr);
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

void quicksort(int a[50], int n){
   int l, b, pi;
   stack *top;
   top = NULL;
   push(&top, 0, n-1);
   while(top != NULL){
      pop(&top, &l, &b);

      partition(a, &pi, l, b);
      if(l < (pi-1)){
         push(&top, l, (pi-1));
      }
      if((pi+1) < b){
         push(&top, (pi+1), b);
      }
   }
}
