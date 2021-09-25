// k Queues in an array
#include<bits/stdc++.h>
using namespace std

class kqueues{
   int *arr, *top, *next, *end;
   int k, next_idx, cap;

   kqueues(int k1, int n){
      k = k1, cap = n;
      arr = new int [cap];
      top = new int [k];                       //[-1, -1, -1]  (storing starting idx of every stack)
      end = new int [k];
      next = new int [cap];                    //[1, 2, 3, 4, 5, -1]

      for(int i = 0; i < k; i++){
         top[i] = -1;
         end[i] = -1;
      }

      next_idx = 0;
      for(int i = 0; i < cap-1; i++){
         next[i] = i+1;
      }
      next[cap-1] = -1; 
   }
}

void push(int item, int qn){  // qn = stack number
   int curr = next_idx;
   next_idx = next[curr];
   if(top[qn] == -1){
        top[qn] = curr;
        end[qn] = curr;
   } else{
        next[end[qn]] = curr;
        end[qn] = curr;
   }
   next[next_idx] = -1;
   arr[curr] = item;
}

int pop(int qn){   
   int curr = top[qn];
   top[qn] = next[curr];
   next[curr] = next_idx;
   next_idx = curr;
return arr[curr];
}

bool isEmpty(int qn){

   if(top[qn] == -1) return true;
return false;
}

