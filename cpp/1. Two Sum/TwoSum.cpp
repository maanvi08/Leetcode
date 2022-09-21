//Source : https://leetcode.com/problems/two-sum/
/**********************************************************************************************
*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
*
*You may assume that each input would have exactly one solution, and you may not use the same element twice.
*
*You can return the answer in any order.
************************************************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>&A , int trgt) {
      // Create a hash table to store the values and the indices
       unordered_map<int,int>h;
        vector<int> res;
      // iterate through the loop
        for(int i = 0;i < A.size();i++)
        {
            int n = trgt - A[i];
            
            if(h.find(n) != h.end())
            {
              //If h contains the value trgt - A[i] return the indices of these two values.
                res.push_back(h[n]);
                res.push_back(i);
                return res;
            }
          //if not add the A[i] to h.
              h[A[i]]=i;
        }
        return res;
    }
};
//Time Complexity : O(n)
