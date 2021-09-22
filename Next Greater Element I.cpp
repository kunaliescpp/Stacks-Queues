/*
Problem Link : https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

Next Greater Element 

Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: N = 4, arr[] = [1 3 2 4]
Output: 3 4 4 -1
Explanation: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist, it is -1.

Example 2:

Input: N = 5, arr[] [6 8 0 1 3]
Output: 8 -1 1 3 -1
Explanation: In the array, the next larger element to  6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.

*/

class Solution{
    public:
    
    // Approach: vector me left to right travel karke stack ko bottom to top fill krenge, end me stack
    // reverse karenge
   
//   Time Complexity : O(n)
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        vector<long long>v;
        stack<long long>stk;
        
        stk.push(arr[n-1]);
        v.push_back(-1);
        
        for(long long i = n-2; i >= 0; i--){
 
            while(!stk.empty() && stk.top() <= arr[i]) stk.pop();
            
            long long nextGreater = (stk.empty()) ? -1 : stk.top();

            v.push_back(nextGreater);
            stk.push(arr[i]);
        }
    
    reverse(v.begin(), v.end());
    
    return v;
    }
};
