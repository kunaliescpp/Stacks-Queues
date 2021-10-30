/*
problem Link: https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

Evaluation of Postfix Expression 

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic
operators like *, /, + and -.

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, we have -4 as result.

Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix expression, we have -3 as result.

*/

class Solution{
    public:
    
    //Function to return precedence of operators
    int prec(char c) {
       
        if(c == '^') return 3;
        else if(c == '/' || c=='*') return 2;
        else if(c == '+' || c == '-') return 1;
        else return -1;
    }


    string infixToPostfix(string s){
        
        stack<char> stk;
        string str;
        for(int i = 0; i < s.size(); i++){
            
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                  str += s[i];
            }
            
            else if(s[i] == '(') stk.push(s[i]);
            
            else if(s[i] == ')'){
                while(stk.top() != '('){
                    str += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            
            else{ // s[i] == operator
                if(stk.empty() == true){
                    stk.push(s[i]);
                } else{
                    if(prec(s[i]) > prec(stk.top())){
                        stk.push(s[i]);
                    }
                    else if(prec(s[i]) < prec(stk.top())){
                        while( !stk.empty() && prec(s[i]) < prec(stk.top())){
                            str += stk.top();
                            stk.pop();
                        }
                        stk.push(s[i]);
                    }
                    else{ // equal precedence -> use associativity
                        str += stk.top();
                        stk.pop();
                        stk.push(s[i]);
                    }
                }
            }
        }
    
        while(stk.empty() == false){
                str += stk.top();
                stk.pop();
        }
     
    return str;       
    }
};
