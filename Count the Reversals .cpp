/*
Problem Link: https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1

Count the Reversals 

Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced 
expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:
Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is: "{{{}}{}}". There is no balanced sequence that can be formed in lesser reversals.

Example 2:
Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance this sequence of braces.

Constraints:
1 ≤ |S| ≤ 105
*/

int countRev (string s){

    stack<int>stk;
    int cnt = 0;

    if(s.size()%2 == 1) return -1;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '{') stk.push(s[i]);

        else if(stk.empty() == true && s[i] == '}'){
           cnt++;
           stk.push('{');
        }

        else stk.pop();
    }   

    cnt += stk.size()/2;

return cnt;
}
