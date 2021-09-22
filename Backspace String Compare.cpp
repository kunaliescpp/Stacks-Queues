/*
Problem Link: https://leetcode.com/problems/backspace-string-compare/

Backspace String Compare

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note: that after backspacing an empty text, the text will continue empty.

 

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a##c", t = "#a#c"
Output: true
Explanation: Both s and t become "c".

Example 4:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 
Follow up: Can you solve it in O(n) time and O(1) space?
*/
  
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char>stk1, stk2;
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] != '#') stk1.push(s[i]);
            
            else{
               if(!stk1.empty()) stk1.pop(); 
            }    
        }
    
        for(int i = 0; i < t.size(); i++){
            
            if(t[i] != '#') stk2.push(t[i]);
            
            else{
              if(!stk2.empty()) stk2.pop();  
            } 
         }
    
        while(!stk1.empty() && !stk2.empty()){
            char c1 = stk1.top();
            stk1.pop();
            char c2 = stk2.top();
            stk2.pop();
            
            if(c1 != c2) return false;
        }
        
        if(!stk1.empty() || !stk2.empty()) return false; 
        
    return true;
    }
};
