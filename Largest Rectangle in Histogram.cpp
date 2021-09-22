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
    
    //Approach : step 1. every element is assumed as smallest block and check in the left side , we want greater and equal element on the left side, then only we make rectangle
    //and maximize the sum. So we multiply the sum after knowing the breadth (by smallest min. on left also maintaing continuity on left i.e. left is left is always smaller, 
    //otherwise we break cotinuity) on the left side 
    
    //step 2 : similarly check on the right side of current element.
    
    // example used : heights[6, 2, 5, 4, 1, 5, 6]
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>stk;  
        int area = 0;
        int n = heights.size();
        
        for(int i = 0; i < heights.size(); i++){
            
            int curr = heights[i];
            while(!stk.empty() && heights[stk.top()] >= heights[i]){  //stack ke top pe always left min of curr
                                                                      //element
                int f = stk.top();                  
                stk.pop();
                curr = heights[f]*(stk.empty() ? i : (i-stk.top()-1));   
                // i-stk.top()-1 = breadth (curr-1 -> left min.)
                area = max(area, curr);
            }
            stk.push(i);
        }
    
       while(!stk.empty()){
           
           int f = stk.top();
           stk.pop();
           int curr = heights[f]*(stk.empty() ? n : (n-stk.top()-1));       //curious last case - multiply last 
           area = max(area, curr);                                      //stack with the total no. of elements
       }                                                                // because it is the smallest stack
    
    return area;
    }
};


