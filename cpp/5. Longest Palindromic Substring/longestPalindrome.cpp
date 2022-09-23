//https://leetcode.com/problems/longest-palindromic-substring/
/*********************************************************************************************************
*Given a string s, return the longest palindromic substring in s.
*
*A string is called a palindrome string if the reverse of that string is the same as the original string.
*
*
*
*Example 1:
*
*Input: s = "babad"
*Output: "bab"
*Explanation: "aba" is also a valid answer.
*Example 2:
*
*Input: s = "cbbd"
*Output: "bb"
**********************************************************************************************************/

class Solution {
public:
   
    bool ispalindrome(string s){
        
        int i=0;
        int j=s.size()-1;
       
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    string longestPalindrome(string s) {
    
        string temp1="";
        for(int i=0;i<s.size();i++){
            string temp2="";
            for(int j=i;j<s.size();j++){
                temp2+=s[j];
                
                if(ispalindrome(temp2)){
                    if(temp2.size()>temp1.size()){
                        temp1=temp2;
                    }
               } 
            }
        }
        
        return temp1;
    }
};
