/*
Problem Link: https://www.geeksforgeeks.org/array-implementation-of-queue-simple/

Queue using array

Implement the functions getFront(), getRear(), enque(), deque().
*/

class Queue{
  public: 
   
  int *arr;
  int front, cap, curr_size;
  Queue(int c){
    arr = new int [c];
    cap = c;
    front = 0;
    curr_size = 0;
  }   
};

bool isFull(){
  return (cap == curr_size);
}

bool isEmpty(){
  return (curr_size == 0);
}

int getFront(){
  if(isEmpty()) return -1;
  else return front;
}

int getRear(){
  if(isEmpty()) return -1;
  else return (front + curr_size - 1)% cap;
}

void enque(){
  if(isFull()) return;
  
  int rear = getRear();
  rear = (rear + 1)% cap;
  arr[rear] = x;
  curr_size++;
}

void deque(){
  if(isEmpty()) return;
  
  front = (front + 1)% cap;
  curr_size--;
}


