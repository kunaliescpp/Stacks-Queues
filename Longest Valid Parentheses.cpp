/*
Problem Link: https://leetcode.com/problems/longest-valid-parentheses/

Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

class Solution {
public:
    // corrction factor : "()(())"  output = 4, expected = 6;
    // correction factor : "()(()"  output = 4, expected = 2;
    int longestValidParentheses(string s) {
        
        int cnt = 0;
        stack<int>stk;
        stk.push(-1);
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '(') stk.push(i);
            
            else{
                stk.pop();
                if(stk.empty()){              // if first char is ')', then stk's top is 0
                    stk.push(i);
                }
                
                else cnt = max(cnt, i-stk.top());
            } 
        
        }
    
   return cnt;
    }
};
