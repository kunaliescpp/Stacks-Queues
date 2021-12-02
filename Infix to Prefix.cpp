    //Function to return precedence of operators
    int prec(char c) {
       
        if(c == '^') return 3;
        else if(c == '/' || c=='*') return 2;
        else if(c == '+' || c == '-') return 1;
        else return -1;
    }


    string infixToPrefix(string s){
        
        stack<char> stk;
        string str;
        for(int i = s.size()-1; i >= 0; i++){
            
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                  str += s[i];
            }
            
            else if(s[i] == ')') stk.push(s[i]);
            
            else if(s[i] == '('){
                while(stk.top() != ')'){
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
                        while(prec(s[i]) < prec(stk.top())){
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
     
        reverse(str.begin(), str.end());

    return str;       
    }



