#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int main(){
   int push(int [], int, int *);
   int pop(int [], int *, int *);
   int partition(int [], int *, int, int);
   int quicksort(int [], int);
   int a[50], n, i, x;
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

int push(int stack[MAX], int x, int (*top)){
    
    if((*top) == MAX-1){
        return 0;
    }else{
        (*top) = (*top) + 1;
        stack[*top] = x;
    }
    //printf("Inside push top = %d\n",stack[*top]);
    return 0;
}

int pop(int stack[MAX], int (*x), int (*top)){
    if((*top) == (-1)){
        return 0;
    }else{
        (*x) = stack[*top];
        (*top) = (*top) - 1;
    }
    //printf("Inside pop top = %d\n",(*x));
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

int quicksort(int a[50], int n){
    int top , stack[MAX], l, b, pi;
    top = (-1);
    //printf("before first 2 push\n");
    push(stack, 0, &top);
    //printf("After first push\n");
    //printf("top = %d\n",top);
    push(stack, (n-1), &top);
    //printf("After second push\n");
    //printf("top = %d\n",top);

    while(top >= 0){
        pop(stack, &b, &top);
        //printf("After pop\n");
        //printf("top = %d and l= %d\n",top,l);
        pop(stack, &l, &top);
        //printf("After pop\n");
        //printf("top = %d and b= %d\n",top,b);

        partition(a, &pi, l, b);
        //printf("partition position = %d\n", pi);
        if((pi-1) > l){
            //printf("before push low = %d, high = %d\n", l, pi-1);
            push(stack, l, &top);
            push(stack, (pi-1), &top);
        }
        if((pi+1) < b){
            //printf("before push low = %d, high = %d\n", pi+1, b);
            push(stack, (pi+1), &top);
            push(stack, b, &top);
        }
    }
}