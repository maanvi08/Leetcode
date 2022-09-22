// source: https://leetcode.com/problems/median-of-two-sorted-arrays/
/*******************************************************************************************************************
*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
*
*The overall run time complexity should be O(log (m+n)).
*
*
*
*Example 1:
*
*Input: nums1 = [1,3], nums2 = [2]
*Output: 2.00000
*Explanation: merged array = [1,2,3] and median is 2.
*Example 2:
*
*Input: nums1 = [1,2], nums2 = [3,4]
*Output: 2.50000
*Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
**********************************************************************************************************************/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n,m;
        n = nums1.size();
        m = nums2.size();
        int i = 0,j=0;
        int m1 = -1,m2 =-1;
        int a = (n+m)/2;
       
        for(int k = 0; k <= a;k++){
            m2 = m1;
            if(i!=n && j!= m){
                if(nums1[i] > nums2[j]){
                    m1 = nums2[j++];
                }
                else
                    m1 =nums1[i++];
            }
            else if (j <m){
                m1 = nums2[j++];
            }
            else{
                m1 = nums1[i++];
            }
           
        }
        
        if((n+m)%2 == 1){
            return m1;
        }
        else{
            return float(m1+m2)/2;
        }
    }
};
//Time Complexity : O(n+m)
//Space Complexity: O(1)
