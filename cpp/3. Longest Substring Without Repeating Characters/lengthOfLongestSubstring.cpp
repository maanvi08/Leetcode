// source :https://leetcode.com/problems/longest-substring-without-repeating-characters/
/****************************************************************************************
*Given a string s, find the length of the longest substring without repeating characters.
*
*
*
*Example 1:
*
*Input: s = "abcabcbb"
*Output: 3
*Explanation: The answer is "abc", with the length of 3.
*Example 2:
*
*Input: s = "bbbbb"
*Output: 1
*Explanation: The answer is "b", with the length of 1.
*Example 3:
*
*Input: s = "pwwkew"
*Output: 3
*Explanation: The answer is "wke", with the length of 3.
*Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*****************************************************************************************/
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <char> nums;
        int z=0;
        int maximum=0;
        for(int i=0;i<s.size();i++)
        {
            auto f= find(nums.begin(),nums.end(),s[i]);
                if(f!=nums.end())
                {
                    nums.erase(nums.begin(),f+1);
                    nums.push_back(s[i]);
                }
            else
            {
                nums.push_back(s[i]);
                z=nums.size();
                maximum=max(maximum,z);
                    
            }
        }
        
        return maximum;
    }
};
