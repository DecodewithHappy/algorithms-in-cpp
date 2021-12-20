#include<stdio.h>
#include<stdlib.h>

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
   printf("Enter the total number of elements: \n");
   scanf("%d",&n);
   printf("Enter array elements: \n");
   for(i=0; i<n; i++)
   {
      scanf("%d",&a[i]);
   }
   quicksort(a, n);
   printf("\nAfter sorting: ");
   for(i=0; i<n; i++){
      printf("%d ",a[i]);
   }
   printf("\n");
   return 0;
}

int push(stack **top, int lb, int ub){
   stack *nn;
   //printf("inside push low = %d, high = %d\n", lb, ub);
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
   //printf("node value inside push nn->%d and nn->%d top->%d and top->%d\n", nn->d1, nn->d2, (*top)->d1, (*top)->d2);
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

   /*printf("\nDisplay array: ");
   for(int i=0; i < ((high-low)+1); i++){
      printf("%d ",a[i]);
   }
   printf("\n");*/
   return 0;
}

void quicksort(int a[50], int n){
   int l, b, pi;
   stack *top;
   top = NULL;
   //printf("before push\n");
   push(&top, 0, n-1);
   //printf("After first push\n");
   //printf("top value after first push top->%d and top->%d\n", top->d1, top->d2);
   while(top != NULL){
      pop(&top, &l, &b);

      partition(a, &pi, l, b);
      //printf("partition position = %d\n", pi);
      if(l < (pi-1)){
         //printf("before push low = %d, high = %d\n", l, pi-1);
         push(&top, l, (pi-1));
      }
      if((pi+1) < b){
         //printf("before push low = %d, high = %d\n", pi+1, b);
         push(&top, (pi+1), b);
      }
   }
}
