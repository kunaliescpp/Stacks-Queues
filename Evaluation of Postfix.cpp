/*
problem Link: https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

Evaluation of Postfix Expression 

// all the operators used in the expression are put at the end (R->L)

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. 
Operators will only include the basic arithmetic operators like *, /, + and -.

Example 1:
Input: S = "231*+9-"
Output: -4

Example 2:
Input: S = "123+*8-"
Output: -3
*/

class Solution{
    public:
    
    int solve(int num1, int num2, char opr){
        
        if(opr == '+') return num2 + num1;
        else if (opr == '-') return num2 - num1;
        else if(opr == '*') return num2 * num1;
        else if(opr == '/') return num2 / num1;
        
    return -1;
    }
    
    int evaluatePostfix(string s){
        
        stack<int> stk;
        string str;
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] >= '0' && s[i] <= '9'){
                stk.push(s[i]- '0');
            } else{ // operator
                int c1 = stk.top(); stk.pop();
                int c2 = stk.top(); stk.pop();
                int res = solve(c1, c2, s[i]);
                
                stk.push(res);
            }
        }   
    
    return stk.top();
    }
};


