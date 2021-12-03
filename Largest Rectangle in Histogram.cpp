/* 
Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1. The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4
 
Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/

class Solution {
public:
    // Time Complexity : O(N);
    
    // stk.top() contains min element
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>stk;  
        int area = 0;
        int n = heights.size();
        
        for(int i = 0; i < heights.size(); i++){
            
            int curr = heights[i];
            while(!stk.empty() && heights[stk.top()] >= heights[i]){  
             
                int f = stk.top();                  
                stk.pop();
                // Remove next smaller and previous smaller
                curr = heights[f]*(stk.empty() ? i-1+1 : (i-stk.top()-1));   
                
                area = max(area, curr);
            }
            stk.push(i);
        }
    
       while(!stk.empty()){
           
           int f = stk.top();
           stk.pop();
           int curr = heights[f]*(stk.empty() ? n : (n-stk.top()-1));      
           area = max(area, curr);                                      
       }                                                               
    
    return area;
    }
};


