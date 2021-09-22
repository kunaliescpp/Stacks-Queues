/*
Infix to Postfix 

Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 

Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation: After converting the infix expression into postfix expression, the resultant expression will be abcd^e-fgh*+^*+i-

Example 2:

Input: str = "A*(B+C)/D"
Output: ABC+*D/
Explanation: After converting the infix expression into postfix expression, the resultant expression will be ABC+*D/
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
