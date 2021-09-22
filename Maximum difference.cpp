/*
Problem Link: https://practice.geeksforgeeks.org/problems/maximum-difference/1

Maximum Difference 

Given array A[] of integers, the task is to complete the function findMaxDiff which finds the maximum absolute difference between nearest left and right smaller element of every element in array.If the element is the leftmost element, nearest smaller element on left side is considered as 0. Similarly if the element is the rightmost elements, smaller element on right side is considered as 0.

Examples:

Input : arr[] = {2, 1, 8}
Output : 1
Left smaller  LS[] {0, 0, 1}
Right smaller RS[] {1, 0, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 1 

Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
Output : 4
Left smaller   LS[] = {0, 2, 4, 4, 4, 7, 2}
Right smaller  RS[] = {0, 3, 7, 3, 3, 3, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 7 - 3 = 4 

Input : arr[] = {5, 1, 9, 2, 5, 1, 7}
Output : 1

Constraints:
1<=T<=100
1<=N<=100
1<=A[ ]<=100
*/

class Solution{
    public:
    
    void leftSmaller(int arr[], int left[], int n){
        
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < n; i++){
            while(!stk.empty() && arr[i] <= arr[stk.top()]){
               stk.pop();
            }
            
            if(!stk.empty()) left[i] = arr[stk.top()];
            
            stk.push(i);
        }
    }
    
    // Approach : |nextSmaller of leftSide - nextSmaller on rightSide|
    int findMaxDiff(int arr[], int n){
      
        int left[n] = {0};
        int right[n] = {0};
        
        leftSmaller(arr, left, n);
        
        reverse(arr, arr+n);
        leftSmaller(arr, right, n);
        // reverse(right, right+n);
    
        int maxi = -1e9;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, abs(left[i]-right[n-1-i]));
        }
    
    return maxi;
    }
};
