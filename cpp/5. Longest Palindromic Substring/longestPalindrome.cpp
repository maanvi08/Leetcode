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
//Brute Force Approach
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
//*******************************************************************************************************
class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        int temp[n][n];
        string res="";
        int l=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=0;
            }
        }
        
        for(int d=0;d<n;d++){
            for(int i=0,j=i+d;j<n;j++,i++){
                
                if(i==j)
                    temp[i][j]=1;
                
                else if(d==1){
                    if(s[i]==s[j]) 
                        temp[i][j]=2;
                    else  
                        temp[i][j]=0;
                }
                
                else{
                    
                    if(s[i]==s[j] && temp[i+1][j-1]){
                        temp[i][j]=temp[i+1][j-1]+2;
                    }
                }
                
                if(temp[i][j]){
                    if(j-i+1>l){
                        l=j-i+1;
                        res=s.substr(i,l);
                    }
                }
            }
            
        }
        
        return res;
    }
};
