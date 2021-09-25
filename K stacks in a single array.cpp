
// k stacks in an array

#include<bits/stdc++.h>
using namespace std

class kstacks{
   int *arr, *top, *next;
   int k, next_idx, cap;

   kstacks(int k1, int n){
      k = k1, cap = n;
      arr = new int [cap];
      top = new int [k];                       //[-1, -1, -1]  (storing starting idx of every stack)
      next = new int [cap];                    //[1, 2, 3, 4, 5, -1]

      for(int i = 0; i < k; i++){
         top[i] = -1;
      }

      next_idx = 0;
      for(int i = 0; i < cap-1; i++){
         next[i] = i+1;
      }
      next[cap-1] = -1; 
   }
}

void push(int item, int sn){  // sn = stack number
   int curr = next_idx;
   next_idx = next[curr];
   next[curr] = top[sn];
   top[sn] = curr;
   arr[curr] = item;
}

int pop(int sn){   
   int curr = top[sn];
   top[sn] = next[curr];
   next[curr] = next_idx;
   next_idx = curr;
return arr[curr];
}

bool isEmpty(int sn){

   if(top[sn] == -1) return true;
return false;
}

