/*
Problem Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

First negative integer in every window of size k 

Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:
Input : N = 5, A[] = {-8, 2, 3, -6, 10}, K = 2
Output : -8 0 -6 -6
Explanation : 
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : N = 8, A[] = {12, -1, -7, 8, -15, 30, 16, 28}, K = 3
Output : -1 -1 -7 -15 -15 0 
 
Constraints:
1 <= N <= 105
1 <= A[i] <= 105
1 <= K <= N
*/

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
  
  vector<long long> v;
  
  int neg = -1;                            // storing -ve value's idx
  for(int i = n-1; i >= n-k; i--){
      if(arr[i] < 0) neg = i;               // fist negative in rightmost window
        
  }

  for(int i = n-k; i >= 0; i--){
      if(arr[i] < 0){
          v.push_back(arr[i]);
          neg = i;
      }
      
      else if( (i+1 <= neg) && (i+k-1 >= neg) )  v.push_back(arr[neg]);
         
      else v.push_back(0);
  }
 
      reverse(v.begin(), v.end());
 return v;
 }
 
