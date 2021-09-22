/*
Problem Link: https://leetcode.com/problems/maximal-rectangle/
  
Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = []
Output: 0

Example 3:
Input: matrix = [["0"]]
Output: 0

Example 4:
Input: matrix = [["1"]]
Output: 1

Example 5:
Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/
    
class Solution {
public:
    int larHist(vector<int>& heights, int n) {                        // largest rec Ar.
        
        stack<int>stk;  
        int area = 0;
        
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
    
    
    // Time complexity: O(r*c);
    int maximalRectangle(vector<vector<char>>& matrix) {
       
        int r = matrix.size();
        if(r == 0) return 0;                                              //* must do
        int c = matrix[0].size();
        
        vector<vector<int>> grid(r, vector<int> (c, 0));
        int Area = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                
                if(i == 0){
                    grid[i][j] = matrix[i][j] - '0'; 
                } else{
                    if(matrix[i][j] == '0') grid[i][j] = 0;
                    else grid[i][j] = grid[i-1][j] + 1;
                }            
            }
            Area = max(Area, larHist(grid[i], c) );
        }
    return Area;
    }
};
