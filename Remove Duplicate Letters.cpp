/*
316. Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 
Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

*/
  
class Solution {
public:
    //Smallest subsequence of distinct characters
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        
        stack<char> stk;
        unordered_map< char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        
        set<char> alreadyinans;
        for(int i = 0; i < n; i++){
            
            mp[s[i]]--;
            if(alreadyinans.count(s[i]) == 1) continue;
            while(!stk.empty() && s[i] < stk.top() && 0 < mp[stk.top()] ){    //Now, mp contains rem freq
                
                char f = stk.top(); stk.pop();
                alreadyinans.erase(f);
            }
            
                stk.push(s[i]);
                alreadyinans.insert(s[i]);   
        }
    
        string str;
        while(!stk.empty()){ 
            char f = stk.top(); stk.pop();
            str += f;
        }
        
        reverse(str.begin(), str.end());
        
    return str;
    }
};
