/*
Evaluation of prefix expression

Input : -+8/632
Output : 8

Input : -+7*45+20
Output : 25
*/

int solve(int num1, int num2, char opr){
    
    if(opr == '+') return num1 + num2;
    else if (opr == '-') return num1 - num2;
    else if(opr == '*') return num1*num2;
    else if(opr == '/') return num2/num1;
    
return -1;
}

int evaluationofPrefix(string &expression) {

    stack<int> stk;
    string str;
    for(int i = s.size()-1; i >= 0; i++){

        if(s[i] >= '0' && s[i] <= '9'){
            stk.push(s[i]- '0');
        } else{ // operator
            int op1 = stk.top(); stk.pop();
            int op2 = stk.top(); stk.pop();
            int res = solve(op1, op2, s[i]);

            stk.push(res);
        }
    }   
return stk.top();
}


