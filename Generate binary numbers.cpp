/*
Problem Link: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1

Generate Binary Numbers 

Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Example 1:
Input: N = 2
Output: 1 10
Explanation: Binary numbers from 1 to 2 are 1 and 10.

Example 2:
Input: N = 5
Output: 1 10 11 100 101
Explanation: Binary numbers from 1 to 5 are 1 , 10 , 11 , 100 and 101.
 
  
Constraints:
1 ≤ N ≤ 106
*/

vector<string> generate(int n){

   vector<string>v;
   queue<string>q;
   q.push("1");
   
   while(n--){
      string s = q.front();
      q.pop();
      v.push_back(s);
      
      q.push(s + "0");
      q.push(s + "1");
   }
return v;
}
