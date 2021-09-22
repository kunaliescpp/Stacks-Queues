/*
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

Reverse First K elements of Queue 

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.

Example 1:
Input:
5 3
1 2 3 4 5
Output: 3 2 1 4 5

Explanation: After reversing the given input from the 3rd position the resultant output will be 3 2 1 4 5.

Example 2:
Input:
4 4
4 3 2 1
Output: 1 2 3 4

Explanation: After reversing the given input from the 4th position the resultant output will be 1 2 3 4.

Constraints:
1 <= N <= 1000
1 <= K <= N
*/

queue<int> modifyQueue(queue<int> q, int k){
    
    stack<int>stk;                                
    for(int i = 0; i < k; i++){              //1,2,3,4,5 (k = 2) ->   
        stk.push(q.front());                   //  curr queue is 3,4,5
        q.pop();
    }
    
    for(int i = 0; i < k; i++){
        q.push(stk.top());                   // curr queue = 3,4,5,2,1
        stk.pop();
    }

    for(int i = 0; i < q.size()-k; i++){
        int f = q.front();                            // curr queue = 2,1
        q.pop();
        q.push(f);
    }
    
return q;
}
