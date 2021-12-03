/*
Problem Link: https://www.geeksforgeeks.org/array-implementation-of-queue-simple/

Queue using array

Implement the functions getFront(), getRear(), enque(), deque().
*/

class Queue{
  public: 
   
  int *arr;
  int front, cap, size;
  Queue(int c){
    arr = new int [c];
    cap = c;
    front = 0;
    size = 0;
  }   
};

bool isFull(){
  return (cap == size);
}

bool isEmpty(){
  return (size == 0);
}

int getFront(){
  if(isEmpty()) return -1;
  else return front;
}

int getRear(){
  if(isEmpty()) return -1;
  else return (front + size - 1)% cap;
}

void enque(){
  if(isFull()) return;
  
  int rear = getRear();
  rear = (rear + 1)% cap;
  arr[rear] = x;
  size++;
}

void deque(){
  if(isEmpty()) return;
  
  front = (front + 1)% cap;
  size--;
}


